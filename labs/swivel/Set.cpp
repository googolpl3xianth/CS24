#include "Set.h"

Node* addNode(const Node* parent){
    Node *newNode = new Node(parent->data);
    if(parent->left != NULL){ newNode->left = addNode(parent->left); }
    if(parent->right != NULL){ newNode->right = addNode(parent->right); }

    return newNode;
}


Set::Set(){
    mRoot = NULL;
    mCount = 0;
}
Set::Set(const Set& other){
    mRoot = addNode(other.mRoot);
    mCount = other.mCount;
}
Set::Set(Set&& other){
    mRoot = other.mRoot;
    mCount = other.mCount;
    other.mRoot = NULL;
    other.mCount = 0;
}
Set::~Set(){
    if(mRoot == NULL){ return; } // empty

    mRoot->deleteNode();

    delete mRoot;
}

size_t Set::clear(){
    if(mRoot == NULL){ return 0; }

    mRoot->deleteNode();

    delete mRoot;
    mRoot = NULL;

    size_t temp = mCount;
    mCount = 0;

    return temp;
}
bool   Set::contains(const std::string& value) const{
    if(mRoot == NULL){ return 0; }

    Node* nodeIndex = mRoot;
    while(nodeIndex != NULL){
        if(value == nodeIndex->data){
            return 1;
        }
        else if(value < nodeIndex->data){
            if(nodeIndex->left == NULL){ return 0; } // Stop 1 before insert
            nodeIndex = nodeIndex->left;
        }
        else{
            if(nodeIndex->right == NULL) { return 0; } // Stop 1 before insert
            nodeIndex = nodeIndex->right;
        }
    }
    return 0;
}
size_t Set::count() const{ return mCount; }
void   Set::debug(){
    print();
    std::cout << "Size: " << mCount << std::endl;
}
size_t Set::insert(const std::string& value){
    Node* newNode = new Node(value);
    if(mRoot == NULL){
        mRoot = newNode;
        mCount++;
        return 1;
    }

    Node* nodeIndex = mRoot;
    while(nodeIndex != NULL){
        if(value == nodeIndex->data){
            delete newNode;
            return 0;
        }
        else if(value < nodeIndex->data){
            if(nodeIndex->left == NULL){ break; } // Stop 1 before insert
            nodeIndex = nodeIndex->left;
        }
        else{
            if(nodeIndex->right == NULL) { break; } // Stop 1 before insert
            nodeIndex = nodeIndex->right;
        }
    }

    if(value < nodeIndex->data){
        nodeIndex->left = newNode;
    }
    else{
        nodeIndex->right = newNode;
    }
    mCount++;
    return 1;
}

void   Set::print() const{
    if(mRoot == NULL){ std::cout << "-" << std::endl; return; }
    std::cout << mRoot->print() << std::endl;
}
size_t Set::remove(const std::string& value){
    if(mRoot == NULL){ return 0; }

    if(!swivel(value)){ return 0; }

    if(mCount == 1){
        delete mRoot;
        mRoot = NULL;
        mCount = 0;
        return 1;
    }
    else if(mRoot->left == NULL){
        Node *temp = mRoot;
        mRoot = mRoot->right;
        delete temp;
        mCount--;
        return 1;
    }
    else if(mRoot->right == NULL){
        Node *temp = mRoot;
        mRoot = mRoot->left;
        delete temp;
        mCount--;
        return 1;
    }
    else{
        Node *nodeIndex = mRoot, *temp = mRoot;
        nodeIndex = nodeIndex->right;
        while(nodeIndex->left != NULL){
            nodeIndex = nodeIndex->left;
        }

        std::string *swivelValue = &nodeIndex->data;
        while(mRoot->data != *swivelValue){
            swivel(*swivelValue);
        }

        mRoot->left = temp->left;
        delete temp;
        mCount--;
        return 1;
    }
}
bool   Set::swivel(const std::string& value){
    if(mRoot == NULL){ return 0; }
    if(mRoot->data == value){ return 1; }

    Node* nodeIndex = mRoot, *parent = mRoot, *temp = mRoot;
    while(nodeIndex != NULL){
        if(value == nodeIndex->data){
            break;
        }

        if(parent != mRoot){
            temp = parent;
        }

        parent = nodeIndex;

        if(value < nodeIndex->data){
            if(nodeIndex->left == NULL){ return 0; } 
            nodeIndex = nodeIndex->left;
        }
        else{
            if(nodeIndex->right == NULL) { return 0; } 
            nodeIndex = nodeIndex->right;
        }
    }

    if(value < parent->data){
        parent->left = nodeIndex->right;
        nodeIndex->right = parent;
    }
    else{
        parent->right = nodeIndex->left;
        nodeIndex->left = parent;
    }
    if(temp == parent){
        mRoot = nodeIndex;
    }
    else if(parent->data < temp->data){
        temp->left = nodeIndex;
    }
    else{
        temp->right = nodeIndex;
    }
    return swivel(value);
}

