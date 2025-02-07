#ifndef NODE_H
#define NODE_H

#include <iostream>
// Use this file to declare your Node type.
// Implement Node member functions and helper functions in Node.cpp.
struct Node{
    std::string data;
    Node *left;
    Node *right;

    Node();
    Node(std::string newData);

    std::string print();
    void deleteNode(); // deletes all of Node's decendents
};

#endif
