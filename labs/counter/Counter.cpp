#include "Counter.h"

// Counter Member Functions
Counter::Counter(){
    mCount = 0;
    mTotal = 0;
}
Counter::~Counter(){
    
}

size_t Counter::count() const{ return mCount; }
int    Counter::total() const{ return mTotal; }

void Counter::inc(const std::string& key, int by){
    Node *temp = map.get(key);
    if(temp == NULL){
        map.insert(key, by);
        mCount++;
    }
    else{
        temp->value += by;
    }
    mTotal+=by;
}
void Counter::dec(const std::string& key, int by){
    Node *temp = map.get(key);
    if(temp == NULL){
        map.insert(key, -1*by);
        mCount++;
    }
    else{
        temp->value -= by;
    }
    mTotal-=by;
}
void Counter::del(const std::string& key){
    mCount--;
    mTotal -= get(key);
    map.remove(key);
}
int  Counter::get(const std::string& key) const{
    Node *temp = map.get(key);
    if(temp == NULL){
        return 0;
    }
    else{
        return temp->value;
    }
}
void Counter::set(const std::string& key, int count){
    Node *temp = map.get(key);
    if(temp == NULL){
        map.insert(key, count);
        mCount++;
        mTotal += count;
    }
    else{
        mTotal += count - temp->value;
        temp->value = count;
    }
}

Counter::Iterator Counter::begin() const{
    Node *temp = map.getTail();
    if(temp == NULL){ return NULL; }
    while(temp->prev != NULL){
        temp = temp->prev;
    }
    Iterator it(temp);
    return it;
}
Counter::Iterator Counter::end() const{
    Iterator it(NULL);
    return it;
}
