#include "Set.h"
#include <iostream>

// Use this file to test your Set class.
// This file won't be graded - do whatever you want.

int main() {
    Set set;
    
    set.print();
    set.insert("d");
    set.insert("b");
    set.insert("e");
    set.insert("a");
    set.insert("c");

    set.debug();

    set.remove("e");
    set.debug();
    set.remove("d");
    set.debug();
    set.remove("a");
    set.debug();
    set.remove("c");
    set.debug();
    set.remove("b");
    set.debug();
    return 0;
}
