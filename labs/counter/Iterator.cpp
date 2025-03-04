#include "Counter.h"

// Counter::Iterator Member Functions
Counter::Iterator::Iterator(){
    mIndex = NULL;
}
Counter::Iterator::Iterator(Node *nodeIndex){
    mIndex = nodeIndex;
}

const std::string& Counter::Iterator::key() const{
    return mIndex->key;
}
int Counter::Iterator::value() const{
    return mIndex->value;
}

void Counter::Iterator::operator ++ (){
    mIndex = mIndex->next;
}
bool Counter::Iterator::operator == (const Iterator& other) const{
    return mIndex == other.mIndex;
}
bool Counter::Iterator::operator != (const Iterator& other) const{
    return mIndex != other.mIndex;
}
