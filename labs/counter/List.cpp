#include "List.h"


List::List(){
    tail = NULL;
}
List::~List(){
    if(tail != NULL){
        Node *temp = tail, *index = tail;
        while(index != NULL){
            index = index->prev;
            delete temp;
            temp = index;
        }
    }
}
void List::insert(Node *newNode){
    if(tail != NULL){
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    else{
        tail = newNode;
    }
}
void List::insert(const std::string &newKey, int newValue){
    Node *newNode = new Node(newKey, newValue);
    insert(newNode);
}
Node* List::get(const std::string &nKey) const{
    Node *index = tail;
    while(index != NULL){
        if(index->key == nKey){
            return index;
        }
        index = index->prev;
    }

    return NULL;
}
Node* List::getTail() const{ return tail; }
int List::remove(const std::string &nKey){
    Node *index = tail;
    while(index != NULL){
        if(index->key == nKey){
            int temp = index->value;
            remove(index);
            return temp;
        }
        index = index->prev;
    }

    return -1;
}
void List::remove(Node *node){
    if(node == tail){
        if(tail->prev == NULL){
            delete tail;
            tail = NULL;
            return;
        }
        tail = tail->prev;
        delete tail;
        tail->next = NULL;
        return;
    }
    else if(node->prev == NULL){
        node->next->prev = NULL;
        delete node;
    }
    node->prev->next = node->next;
    node->next->prev = node->prev;
    delete node;
}
void List::print() const{
    if(tail != NULL){
        print(tail);
    }
}
void List::print(Node *node) const{
    if(node->prev != NULL){
        print(node->prev);
    }
    node->print();
}

