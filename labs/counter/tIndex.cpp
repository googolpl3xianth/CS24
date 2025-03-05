#include "Index.h"
#include <iostream>

using namespace std;

int main(){
    Hashmap map;
    List list;
    Node *temp;
    temp = new Node("no",1);
    
    list.insert(temp);
    map.insert(temp);
    
    map.print();

    temp = new Node("huh", 2);
    list.insert(temp);
    map.insert(temp);

    map.print();
    
    temp = new Node("wat", 5);
    list.insert(temp);
    map.insert(temp);
    
    if(map.get("no") != NULL){
        map.get("no")->print();
    }
    else{
        map.print();
    }
    return 0;
}
