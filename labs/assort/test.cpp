#include "List.h"
#include <iostream>

// Use this file to test your List class!
// This file won't be graded - do whatever you want.

int main() {
    List list;
        

    list.insert("Clotho");
    list.insert("Lachesis");
    list.insert("Atropos");
    list.insert("Clotho");
    list.insert("Lachesis");
    list.insert("Atropos");

    list.print();

    std::cout << list.remove("Clotho") << std::endl;

    list.print();
    

    return 0;
}
