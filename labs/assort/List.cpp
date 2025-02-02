#include "List.h"
#include <iostream>
using namespace std;

/*
*Node deleteNode(Node &nodeIndex){
    if(nodeIndex)
    delete deleteNode(nodeIndex);
}*/

List::List(){
    head = NULL;
}

List::List(const List& other){
    if(other.head == NULL){ // empty list
        head = NULL;
        return;
    }
    Node *newHead = new Node;
    head = newHead;
    newHead->data = other.head->data; // copy head
    
    if(other.head->next == NULL){ // if just head
        return;
    }

    Node *nodeIndex = other.head->next, *copyIndex = head;

    while(nodeIndex->next != NULL){ // body
        Node *newNode = new Node;
        newNode->data = nodeIndex->data;
        copyIndex->next = newNode;
        copyIndex = newNode;
        nodeIndex = nodeIndex->next;
    }
    
    Node *newNode = new Node; // tail
    newNode->data = nodeIndex->data;
    newNode->next = NULL;
    copyIndex->next = newNode;
}

List::~List(){
    if(head == NULL){
        return;
    }
    Node *nodeIndex = head->next, *temp = head;
    do{ 
        delete temp;
        temp = nodeIndex;
        nodeIndex = nodeIndex->next;
    } while(nodeIndex != NULL);
    delete temp;
}

size_t List::count() const{
    size_t count = 0;
    Node *nodeIndex = head;
    while(nodeIndex != NULL){
        count++;
        nodeIndex = nodeIndex->next;
    }
    return count;
}

void List::insert(const std::string& value){
    Node *newNode = new Node;
    newNode->data = value;
    if(head == NULL){ // first entry
        newNode->next = NULL;
        head = newNode;
        return;
    }
    if(head->data > value){ // insert at head
        Node *temp;
        temp = head;
        head = newNode;
        newNode->next = temp;
        return;
    }
 
    Node *nodeIndex;
    nodeIndex = head;
    while(nodeIndex->next != NULL){ // insert middle
        if(nodeIndex->next->data > value){
            Node *temp;
            temp = nodeIndex->next;
            nodeIndex->next = newNode;
            newNode->next = temp;
            return;
        }
        nodeIndex = nodeIndex->next;
    }
    nodeIndex->next = newNode; // insert end
    newNode->next = NULL;
}

const std::string& List::lookup(size_t index) const{
    if(head == NULL){
        throw std::out_of_range("Empty List");
    }
    Node *nodeIndex = head;
    for(size_t i = 0; i < index; i++){
        nodeIndex = nodeIndex->next;
        if(nodeIndex == NULL){
            throw std::out_of_range("Size: " + std::to_string(count()) + " Index: " + std::to_string(index));
        }
    }
    return nodeIndex->data;
}

void List::print(bool reverse) const{
    Node *nodeIndex = head;
    std::cout << "[";
    if(reverse && nodeIndex != NULL){
        std::string tempStr = nodeIndex->data;
        while(nodeIndex->next != NULL){
            nodeIndex = nodeIndex->next;
            tempStr = nodeIndex->data + ", " + tempStr;
        }
        std::cout << tempStr;
    }
    else{
        while(nodeIndex != NULL){
            std::cout << nodeIndex->data;
            if(nodeIndex->next != NULL){
                std::cout << ", ";
            }
            nodeIndex = nodeIndex->next;
        }
    }
    std::cout << "]" << std::endl;
}
std::string List::remove(size_t index){
    if(head == NULL){
        throw std::out_of_range("Empty List");
    }
    Node *nodeIndex = head;
    string tempData;
    if(index == 0){ // head
        tempData = head->data;
        head = head->next;
        delete nodeIndex;
        return tempData;

    }

    for(size_t i = 0; i < index-1; i++){
        nodeIndex = nodeIndex->next;
        if(nodeIndex == NULL){
            throw std::out_of_range("Size: " + std::to_string(count()) + " Index: " + std::to_string(index));
        }
    }
    if(nodeIndex->next == NULL){
        throw std::out_of_range("Size: " + std::to_string(count()) + " Index: " + std::to_string(index));
    }

    Node *temp = nodeIndex->next;
    nodeIndex->next = temp->next;
    tempData = temp->data;

    delete temp;
    
    return tempData;
}
size_t List::remove(const std::string& value){
    if(head == NULL){
        return 0;
    }
    Node *nodeIndex = head, *temp;
    size_t numRm = 0;

    if(head->data == value){ // Head
        while(nodeIndex->data == value){
            temp = nodeIndex;
            nodeIndex = nodeIndex->next;
            delete temp;
            numRm++;
            if(nodeIndex == NULL){
                break;
            }
        }
        head = nodeIndex;
        return numRm;
    }

    while(nodeIndex->next->data != value){ // find first instance
        nodeIndex = nodeIndex->next;
        if(nodeIndex == NULL){
            return numRm;
        }
    }
    Node *connect = nodeIndex;
    nodeIndex = nodeIndex->next;
    while(nodeIndex->data == value){
        temp = nodeIndex;
        nodeIndex = temp->next;
        delete temp;
        numRm++;
        if(nodeIndex == NULL){
            break;
        }
    }
    connect->next = nodeIndex;
    return numRm;
}
