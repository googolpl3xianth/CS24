#ifndef LIST_H
#define LIST_H

#include <string>
#include <iostream>
struct Node{
    Node *next;
    Node *prev;
    std::string key;
    int value;

    Node(const std::string &newKey, int newValue){
        next = NULL;
        prev = NULL;
        key = newKey;
        value = newValue;
    }
    void print() const{
        std::cout << "[" << key << ", " << value << "]" << std::endl;
    }
};

class List{
    Node *tail;

    public:
        List();
        ~List();

        void insert(Node *newNode);
        void insert(const std::string &newKey, int newValue);
        Node* get(const std::string &nKey) const;
        Node* getTail() const;
        int remove(const std::string &nKey);
        void print() const;

    private:
        void remove(Node *node);
        void print(Node *node) const;
};

#endif
