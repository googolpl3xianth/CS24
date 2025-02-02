#include "List.h"
#include <iostream>

// Use this file to test your List class!
// This file won't be graded - do whatever you want.

int main() {
    List list;
        

    list.insert("Clotho");

    list.print();
    List copy(list);
    copy.print();
    list.print();
    
    
    return 0;
}
