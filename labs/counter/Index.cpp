#include "Index.h"

// Index Member Functions
Hashmap::Hashmap(){
    mTable = new Node*[3]{NULL};
    markNode = new Node(true);
    mCount = 0;
    mCapacity = 3;

}
Hashmap::Hashmap(size_t capacity){
    mTable = new Node*[capacity]{NULL};
    markNode = new Node(true);
    mCount = 0;
    mCapacity = capacity;
}
Hashmap::~Hashmap(){
    delete [] mTable;
    delete markNode;
}

size_t Hashmap::count(){ return mCount; }
size_t Hashmap::capacity(){ return mCapacity; }
size_t Hashmap::hash(const std::string &key, bool insert) const{
    size_t index = 0, i = 0;
    for(char a : key){
        index += a;
    }

    index %= mCapacity;
    while(mTable[index] != NULL && (!insert || !mTable[index]->marked) && mTable[index]->key != key){
        i++;
        index += i;
        if(index >= mCapacity){
            index -= mCapacity;
        }
    }

    //std::cout << "Collisions: " << i << std::endl;//
    return index;
}
Node* Hashmap::get(const std::string &key) const{
    size_t hashIndex = hash(key);
    if(mTable[hashIndex] == NULL || mTable[hashIndex]->marked){
        return NULL;
    }
    else{
        return mTable[hashIndex];
    }
}
void Hashmap::insert(Node *newNode){
    if(mCount+1 > mCapacity / 2){     
        Node **temp = mTable;
        mTable = new Node*[mCapacity*2]{NULL};
        for(size_t i = 0; i < mCapacity; i++){
            if(temp[i] == NULL || temp[i]->marked){ continue; }
            mTable[hash(temp[i]->key)] = temp[i];
        }
        delete [] temp;
        mCapacity*=2;
    }
    mCount++;
    mTable[hash(newNode->key, true)] = newNode;
}
int Hashmap::remove(const std::string &key){
    size_t temp = hash(key);
    int tempCount = mTable[temp]->value;

    mTable[temp] = markNode;
    return tempCount;
}
void Hashmap::print(){
    for(size_t i = 0; i < mCapacity; i++){
        if(mTable[i] == NULL || mTable[i]->marked){
            std::cout << "NULL ";
        }
        else{
            std::cout << mTable[i]->key << " ";
        }
    }
    std::cout << std::endl;
}
