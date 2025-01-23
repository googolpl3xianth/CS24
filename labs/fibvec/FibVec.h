#ifndef FIBVEC_H
#define FIBVEC_H

// This provides the size_t type:
#include <cstddef>

class FibVec {
    int *_vec, _size, _cap, _prevCap;

    void upCap();

public:
    FibVec();
    ~FibVec();

    int capacity();
    int count();
    void insert(int value, int index);
    int lookup(int index);
    int pop();
    void push(int value);
    int remove(int index);
    void print();
};

#endif
