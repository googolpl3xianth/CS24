#ifndef FIBVEC_H
#define FIBVEC_H

// This provides the size_t type:
#include <cstddef>

class FibVec {
    int *_vec;
    size_t _size, _cap, _prevCap;
    bool _verbose;

    void fibCap(bool up);

public:
    FibVec();
    FibVec(bool v);
    ~FibVec();

    size_t capacity() const;
    size_t count() const;
    void insert(int value, size_t index);
    int lookup(size_t index) const;
    int pop();
    void push(int value);
    int remove(size_t index);
    void print() const;
};

#endif
