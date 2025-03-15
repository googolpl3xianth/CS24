#include "Map.h"

#include <queue>
#include <cmath>
#include <set>

Point anchor(Point *p1, const Point *p2){
    p1->move(p1->getLat() - p2->getLat(), p1->getLng() - p2->getLng());
    return *p1;
}

void addToQueue(std::priority_queue<Point, std::vector<Point>, ComparePoints> q, std::set<Point*> s, Point *p, const Point *dst){
    if(p == dst){
        return;
    }
    if(s.find(p) == s.end()){
        q.push(anchor(p, dst));
        s.insert(p);
        if(p1->getLat() != 0){
            q.push(anchor(p
        }
    }
}


// Member Functions
Map::Map(std::istream& stream){
    bombCount = 0;
    char temp;
    Point *tempPt;
    std::vector<Point*> tempRow;
    size_t lat = 0, lng = 0;
    while(stream.get(temp)){
        if(temp == '\n'){
            grid.push_back(tempRow);
            tempRow.clear();
            lat++;
            lng = 0;
        }
        else{
            if(temp == '*'){
                tempPt = new Point(lat, lng, temp);
                bombLoc.push_back(tempPt);
            }
            tempPt = new Point(lat, lng, temp);
            tempRow.push_back(tempPt);
            lng++;
        }
    }
    for(size_t i = 0; i < grid.size(); i++){
        for(size_t j = 0; j < grid[0].size(); j++){
            std::cout << grid[i][j]->value;
        }
        std::cout << std::endl;
    }//
}
Map::~Map(){
    for(size_t i = 0; i < grid.size(); i++){
        for(size_t j = 0; j < grid[0].size(); j++){
            delete grid[i][j];
        }
    }
}

std::string Map::route(Point src, Point dst){
    if(isValid(src) || grid[src.getLat()][src.getLng()]->value == '#' || grid[src.getLat()][src.getLng()]->value == '~'){
        throw PointError(src);
    }
    if(isValid(dst)){
        throw PointError(dst);
    }
    
    std::string path = "";
    
    std::set<Point*> searched;
    Point *index = &src;
    

    while(!Q.empty()){
        std::cout << Q.top() << std::endl;
        Q.pop();
    } //*

    return "";
}

bool Map::isValid(const Point &pt){
    if(pt.getLat() < 0 || pt.getLat() >= int(grid.size()) || pt.getLng() < 0 || pt.getLng() >= int(grid[0].size())){
        return false;
    }
    return true;
}

void tryEdge(
