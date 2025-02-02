#include "List.h"
#include <iostream>

// Use this file to test your List class!
// This file won't be graded - do whatever you want.

int main() {
    List list;
    
    list.insert("Atropos");
    list.insert("Clotho");
    list.insert("Lachesis");
    list.print(); 
    
    list.remove("No");
    //list.remove("Macavity");
    //list.remove("");
    //list.print();
    
    return 0;
}
