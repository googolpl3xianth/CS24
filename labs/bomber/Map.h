#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <string>
#include <vector>

#include "Point.h"
#include "Errors.h"

class Map {
    std::vector<std::vector<Point*>> grid;
    //std::priority_queue<Edge path, std::vector<Point>, ComparePoints> Q;
    std::vector<Point*> bombLoc;
    size_t bombCount;
public:
    Map(std::istream& stream);
    ~Map();

    std::string route(Point src, Point dst);
private:
    bool isValid(Point pt);
    
};

struct Edge{
    Point *start;
    Point *end;
    char direction;

    Edge(Point *start, Point *end){
        if(start->getLat() == end->getLat()){
            if(start->getLng() < end->getLng()){
                direction = 'e';
            }
            else{
                direction = 'w';
            }
        }
        else{
            if(start->getLat() < end->getLat()){
                direction = 's';
            }
            else{
                direction = 'n';
            }
        }
    }
};

struct path{
    


}



#endif
