#include "FibVec.h"
#include <iostream>
// This provides exception types:
#include <stdexcept>

FibVec::FibVec(){
    _size = 0;
    _cap = 1;
    _prevCap = 1;
    _verbose = false;
    _vec = new int[_cap];
}
FibVec::FibVec(bool v){
    _size = 0;
    _cap = 1;
    _prevCap = 1;
    _verbose = v;
    _vec = new int[_cap];
}

FibVec::~FibVec(){
    delete [] _vec;
}

size_t FibVec::capacity() const { return _cap; }

size_t FibVec::count() const { return _size; };

void FibVec::insert(int value, size_t index){
    if(index > _size){ throw std::out_of_range("Insertion failed, size: " + std::to_string(_size) + " index: " + std::to_string(index)); }

    fibCap(true);
    
    for(size_t i = _size; i > index; i--){
        _vec[i] = _vec[i-1];
    }

    _vec[index] = value;
    _size++;
}

int FibVec::lookup(size_t index) const { 
    if(index >= _size){ throw std::out_of_range("Lookup failed, size: " + std::to_string(_size) + " index: " + std::to_string(index)); }
    if(_verbose){ std::cout << "fibvec[" << std::to_string(index) << "] = " << std::to_string(_vec[index]) << std::endl;}
    return _vec[index]; 
}

int FibVec::pop(){
    if(_size == 0){ throw std::underflow_error("Pop failed, vector empty"); }
    else{ 
        _size--; 
        int temp = _vec[_size];
        fibCap(false); 
        if(_verbose){
            std::cout << "popped " << std::to_string(temp) << std::endl;
            print();
        }
        return temp; 
    }
}

void FibVec::push(int value){
    fibCap(true);
    _vec[_size] = value;
    _size++;
}

int FibVec::remove(size_t index){
    if(index >= _size){ throw std::out_of_range("Remove failed, size: " + std::to_string(_size) + " index: " + std::to_string(index)); }

    int temp = _vec[index];

    for(size_t i = index; i < _size-1; i++){
        _vec[i] = _vec[i+1];
    }

    _size--;
    fibCap(false);
    return temp;
}

void FibVec::print() const {
    std::cout << "[" << std::to_string(_size) << "/" << std::to_string(_cap) << "]: ";
    if(_size != 0){
        for(size_t i = 0; i < _size; i++){
            std::cout << std::to_string(_vec[i]) << " ";
        }
    }
    std::cout << std::endl;
}

void FibVec::fibCap(bool up){
    if(up){
        if(_size >= _cap){
            _cap += _prevCap;
            _prevCap = _cap - _prevCap;
    
            int *tempVec = new int[_cap];
            for(size_t i = 0; i < _size; i++){
                tempVec[i] = _vec[i];
            }

            delete [] _vec;
            _vec = tempVec;
        }
    }
    else{
        if(_size < _cap - _prevCap){
            _prevCap = _cap - _prevCap;
            _cap -= _prevCap;

            int *tempVec = new int[_cap];
            for(size_t i = 0; i < _size; i++){
                tempVec[i] = _vec[i];
            }

            delete [] _vec;
            _vec = tempVec;
        }
    }
}
