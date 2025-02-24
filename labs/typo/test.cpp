#include "Heap.h"
#include <iostream>

// Use this file to test your Heap class!
// This file won't be graded - do whatever you want.

int main() {
    Heap heap(8);
    
    heap.push("10", 10);
    heap.push("7", 7);
    heap.push("8", 8);
    heap.push("1", 1);
    heap.push("5", 5);
    heap.push("3", 3);
    heap.push("37", 37);
    heap.push("9", 9);
    heap.pushpop("5", 5);
    heap.pushpop("20", 20);
    heap.pushpop("9", 9);
    heap.pushpop("11", 11);
    heap.pushpop("1", 1);



    /*std::cout << heap.lookup(0).value << std::endl;
    std::cout << heap.lookup(1).value << std::endl;
    std::cout << heap.lookup(2).value << std::endl;*/

    size_t count = heap.count();
    for(size_t i = 0; i < count; i++){
        std::cout << i << " " << heap.pop().value << std::endl;
    }

    return 0;
}
