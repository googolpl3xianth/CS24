#ifndef MAP_H
#define MAP_H

#include <string>
#include <vector>
#include <unordered_set>

#include "Point.h"
#include "Errors.h"

class Map {
    std::vector<std::vector<Point*>> grid;

public:
    Map(std::istream& stream);
    ~Map();
    
    std::string route(Point src, Point dst);
private:
    bool move(Point *&pt, char dir);
    bool isValid(int lat, int lng);
    bool isValid(const Point &pt);
};


struct Path{
    std::string dir = "";
    Point *pt;
    int bombs = 0;
    std::unordered_set<Point*> B; // bombs collected
    std::unordered_set<Point*> W; // walls destroyed
    Path(Point *newPt){
        pt = newPt;
        if(pt->value == '*'){
            bombs = 1;
            B.insert(newPt);
        }
    }
    Path(Path pa, Point *newPt, char newDir, int bomb=0){
        pt = newPt;
        dir = pa.dir + newDir;
        bombs = pa.bombs + bomb;
        B = pa.B;
        W = pa.W;
        if(bomb == 1){
            B.insert(newPt);
        }
        else if(bomb == -1){
            W.insert(newPt);
        }
    }
};

struct ComparePoints{
    bool operator()(const Path &p1, const Path &p2){
        if(p1.pt->mag > p2.pt->mag){       return true;                }
        else if(p1.pt->mag == p2.pt->mag){ return p1.bombs < p2.bombs; }
        else{                              return false;               }
    }
};



#endif
