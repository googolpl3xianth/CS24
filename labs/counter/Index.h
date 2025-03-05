#ifndef INDEX_H
#define INDEX_H

#include "List.h"

class Hashmap{
    public:
        Hashmap();
        Hashmap(size_t capacity);
        ~Hashmap();

        size_t count();
        size_t capacity();
        size_t hash(const std::string &key, bool insert = false) const;
        Node* get(const std::string &key) const;
        void insert(Node *newNode);
        int remove(const std::string &key);
        void print();

    private:
        Node **mTable;
        Node *markNode;
        size_t mCount;
        size_t mCapacity;
};

#endif
