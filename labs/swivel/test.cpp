#include "Set.h"
#include <iostream>

// Use this file to test your Set class.
// This file won't be graded - do whatever you want.

int main() {
    Set set;
    /*
    set.print();
    set.insert("Morris");
    set.insert("Leyland");
    set.insert("Standard");
    set.insert("Stright");
    set.insert("Wolseley");
    set.insert("Rover");
    set.insert("Bentley");
    set.insert("Mercury");*/

    set.debug();

    Set copy(set);
    set.debug();
    copy.debug();
    return 0;
}
