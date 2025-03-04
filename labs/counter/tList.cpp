#include "List.h"
#include <iostream>
using namespace std;

int main(){
    List list;

    list.insert("yep", 1);
    list.insert("nope", 5);
    list.insert("hi", 6);

    list.get("nope");
    
    std::string s = "nope";
    list.remove(s);
    list.print();


    return 0;
}
