#include "Heap.h"
#include <iostream>

size_t parent(size_t index){ return (index-1) / 2; }
size_t leftChild(size_t index){ return (index * 2 + 1); }
size_t rightChild(size_t index){ return (index * 2 + 2); }

void swap(Heap::Entry* heap, size_t i1, size_t i2){
    //std::cout << "i1: " << heap[i1].value << ", " << heap[i1].score << " i2: " << heap[i2].value << ", " << heap[i2].score << std::endl;
    Heap::Entry temp = heap[i1];
    heap[i1] = heap[i2];
    heap[i2] = temp;
    //std::cout << "After swap i1: " << heap[i1].value << ", " << heap[i1].score << " i2: " << heap[i2].value << ", " << heap[i2].score << std::endl;

}

// Recursively checks if an entry is smaller than it's children or parent is bigger then entry, then swaps until fixed
void minSwap(Heap::Entry* heap, const size_t &count, size_t index){
    size_t left = leftChild(index);
    size_t right = rightChild(index);
    size_t parentIndex = parent(index);
  
    if(right < count){ // both children exists
        if(heap[right].score < heap[left].score ){
            if(heap[right].score < heap[index].score){
                swap(heap, index, right);
                minSwap(heap, count, right);
                return;
            }
        }
    }
    if(left < count){ // left exists
        if(heap[left].score < heap[index].score){
            swap(heap, index, left);
            minSwap(heap, count, left);
            return;
        }
    }
    if(index != 0 && heap[parentIndex].score > heap[index].score){
        swap(heap, index, parentIndex);
        minSwap(heap, count, parentIndex);    
    }
}


Heap::Heap(size_t capacity){
    mData = new Entry[capacity] {"", 0};
    mCapacity = capacity;
    mCount = 0;
}
Heap::Heap(const Heap& other){
    mCapacity = other.mCapacity;
    mCount = other.mCount;
    mData = new Entry[mCapacity];
    for(size_t i = 0; i < mCount; i++){
        mData[i] = other.mData[i];
    }
}
Heap::Heap(Heap&& other){
    mData = other.mData;
    mCapacity = other.mCapacity;
    mCount = other.mCount;
    other.mData = NULL;
}
Heap::~Heap(){
    delete [] mData;
}

size_t       Heap::capacity() const{ return mCapacity; }
size_t       Heap::count() const{ return mCount; }
const Heap::Entry& Heap::lookup(size_t index) const{ return mData[index]; }
Heap::Entry        Heap::pop(){
    if(mCount == 0){ throw std::underflow_error("Empty list"); }

    Entry temp = mData[0];
    mCount--;
    mData[0] = mData[mCount];
    minSwap(mData, mCount, 0);

    return temp;
}
Heap::Entry        Heap::pushpop(const std::string& value, float score){
    if(mCount == 0){ throw std::underflow_error("Empty list"); }

    Entry temp = mData[0];

    mData[0].value = value;
    mData[0].score = score;

    minSwap(mData, mCount, 0);
    
    return temp;
}
void         Heap::push(const std::string& value, float score){
    if(mCount >= mCapacity){ throw std::overflow_error("Attempt to add: " + value + " Size: " + std::to_string(mCount) + " Capacity: " + std::to_string(mCapacity)); }

    mData[mCount].value = value;
    mData[mCount++].score = score;
    minSwap(mData, mCount, mCount-1);
}
const Heap::Entry& Heap::top() const{
    return mData[0];
}
