#include "FibVec.h"
#include <iostream>
// This provides exception types:
#include <stdexcept>

FibVec::FibVec(){
    _size = 0;
    _cap = 1;
    _prevCap = 1;
    _vec = new int[_cap];
}

FibVec::~FibVec(){
    delete [] _vec;
}

int FibVec::capacity(){ return _cap; }

int FibVec::count(){ return _size; };

void FibVec::insert(int value, int index){
    if(index > _size || index < 0){ throw std::out_of_range("Insertion failed, size: " + std::to_string(_size) + " index: " + std::to_string(index)); }

    upCap();
    
    for(int i = _size; i > index; i--){
        _vec[i] = _vec[i-1];
    }

    _vec[index] = value;
    _size++;
}

int FibVec::lookup(int index){ if(index > _size || index < 0){ throw std::out_of_range("Lookup failed, size: " + std::to_string(_size) + " index: " + std::to_string(index)); } return _vec[index]; }

int FibVec::pop(){
    if(_size == 0){ throw std::underflow_error("Pop failed, vector empty"); }
    else{ _size--; return _vec[_size]; }
}

void FibVec::push(int value){
    upCap();
    _vec[_size] = value;
    _size++;
}

int FibVec::remove(int index){
    if(index > _size || index < 0){ throw std::out_of_range("Remove failed, size: " + std::to_string(_size) + " index: " + std::to_string(index)); }

    int temp = _vec[index];

    for(int i = index; i < _size-1; i++){
        _vec[i] = _vec[i+1];
    }

    _size--;
    return temp;
}

void FibVec::print(){
    std::cout << "[";
    for(int i = 0; i < _size-1; i++){
        std::cout << std::to_string(_vec[i]) << ", ";
    }
    if(_size > 0){
        std::cout << std::to_string(_vec[_size-1]);
    }
    std::cout << "] " << "Capacity: " << std::to_string(_cap) << std::endl;
}

void FibVec::upCap(){
    if(_size >= _cap){
        int temp = _cap;
        _cap += _prevCap;
        _prevCap = temp;
    
        int *tempVec = new int[_cap];
        for(int i = 0; i < _size; i++){
            tempVec[i] = _vec[i];
        }

        delete [] _vec;
        _vec = tempVec;
    }
}
