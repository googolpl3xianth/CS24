#include "FibVec.h"
#include <iostream>

// Use this file to test your FibVec class!
// This file won't be graded - do whatever you want.

int main() {
    FibVec fibvec(true);
    
    fibvec.push(0);
    fibvec.push(1);
    fibvec.push(5);
    fibvec.push(12);
    fibvec.push(22);
    fibvec.push(35);
    fibvec.push(51);
    fibvec.push(70);
    fibvec.push(92);
    fibvec.push(117);
    fibvec.push(145);
    fibvec.push(176);
    fibvec.print();

    try{fibvec.remove(12);} 
    catch(const std::out_of_range& e){ std::cout << "Error: " << e.what() << std::endl; }
    try{fibvec.remove(0);} 
    catch(const std::out_of_range& e){ std::cout << "Error: " << e.what() << std::endl; }

    fibvec.print();




    /*
    fibvec.push(100);
    fibvec.push(200);
    fibvec.print();
    fibvec.pop();
    fibvec.pop();*/

    /*fibvec.push(1);
    fibvec.print();
    fibvec.push(2);
    fibvec.print();
    fibvec.push(3);
    fibvec.print();
    fibvec.push(4);
    fibvec.print();
    fibvec.push(5);
    fibvec.print();
    fibvec.push(6);
    fibvec.print();
    fibvec.push(7);
    fibvec.print();*/

    /*std::cout << "Count: " << std::to_string(fibvec.count()) << std::endl;
    std::cout << "Capacity: " << std::to_string(fibvec.capacity()) << std::endl;
    fibvec.print();
    fibvec.insert(1, 0);
    fibvec.print();
    try{
        fibvec.insert(2, 2);
    }
    catch(const std::out_of_range& e){
        std::cerr << "Error: " << e.what() << std::endl;
    }
    try{
        fibvec.insert(2, -1);
    }
    catch(const std::out_of_range& e){
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << std::to_string(fibvec.lookup(0)) << std::endl;
    fibvec.pop();
    fibvec.print();
    try{
        fibvec.pop();
    }
    catch(const std::underflow_error& e){
        std::cerr << "Error: " << e.what() << std::endl;
    }
    fibvec.push(2);
    fibvec.push(3);
    fibvec.print();
    fibvec.insert(1, 0);
    fibvec.print();
    fibvec.remove(1);
    fibvec.print();*/




  return 0;
}
