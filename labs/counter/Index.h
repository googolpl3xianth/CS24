#ifndef INDEX_H
#define INDEX_H

// TODO...
#include "List.h"

class Hashmap{
    public:
        Hashmap();
        Hashmap(size_t capacity);
        ~Hashmap();

        size_t count();
        size_t capacity();
        size_t hash(const std::string &key);
        Node* get(const std::string &key);
        void insert(Node *newNode);

    private:
        Node **mTable;
        size_t mCount;
        size_t mCapacity;
};

#endif
