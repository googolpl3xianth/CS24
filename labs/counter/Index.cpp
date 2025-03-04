#include "Index.h"

// Index Member Functions
Hashmap::Hashmap(){
    mTable = new *Node[3]{NULL}
    mCount = 0;
    mCapacity = 2;

}
Hashmap::Hashmap(const size_t &capacity){
    mTable = new *Node[capacity]{NULL}
    mCount = 0;
    mCapacity = capacity;
}
Hashmap::~Hashmap(){
    delete [] mTable;
}

size_t Hashmap::count(){ return mCount; }
size_t Hashmap::capacity(){ return mCapacity; }
size_t Hashmap::hash(const std::string &key){
    size_t index = 0, i = 0;
    for(char a : key){
        index += a;
    }

    index %= mCapacity;
    while(mTable[index] != NULL && mTable[index]->key != key){
        i++;
        index += i;
        if(index >= mCapacity){
            index -= mCapacity;
        }
    }
    
    return index;
}
Hashmap::Node* Hashmap::get(const std::string &key){
    size_t hashIndex = hash(key);
    if(mTable[hashIndex] == NULL){
        return NULL;
    }
    else{
        return mTable[hashIndex]
    }
}
void Hashmap::insert(Node *newNode){
    if(mCount+1 >= mCapacity / 2){
        Node **temp = mTable;

        mCapacity *= 2;
        mTable = new Node*[mCapacity];
        for(Node *node : temp){
            mTable[hash(node->key)] = node;
        }
    }
    count++;
    mTable[hash(newNode->key)] = newNode;
}
