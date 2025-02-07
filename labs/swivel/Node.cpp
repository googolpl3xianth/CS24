#include "Node.h"

Node::Node(){
    left = NULL;
    right = NULL;
}

Node::Node(std::string newData){
    data = newData;
    left = NULL;
    right = NULL;
}

std::string Node::print(){
    if(left == NULL && right == NULL){
        return data;
    }
    else{
        std::string leftData, rightData;

        if(left == NULL){leftData = '-';}
        else{ leftData = left->print();}
        if(right == NULL){rightData = '-';}
        else{ rightData = right->print();}

        return "(" + leftData + " " + data + " " + rightData + ")";
    }
}

void Node::deleteNode(){
    if(left != NULL){ left->deleteNode(); delete left;}
    if(right != NULL){ right->deleteNode(); delete right;}
}
