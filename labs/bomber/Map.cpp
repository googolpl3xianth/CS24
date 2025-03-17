#include "Map.h"

#include <queue>
#include <unordered_map>

bool Map::move(Point *&pt, char dir){
    if(dir == 'n'){
        if(!isValid(pt->lat-1,pt->lng)){ return false; }
        pt = grid[pt->lat-1][pt->lng];
    }
    else if(dir == 'e'){
        if(!isValid(pt->lat,pt->lng+1)){ return false; }
        pt = grid[pt->lat][pt->lng+1];
    }
    else if(dir == 's'){
        if(!isValid(pt->lat+1,pt->lng)){ return false; }
        pt = grid[pt->lat+1][pt->lng];
    }
    else{ // w
        if(!isValid(pt->lat,pt->lng-1)){ return false; }
        pt = grid[pt->lat][pt->lng-1];
    }
    return true;
}

void checkPath(std::priority_queue<Path, std::vector<Path>, ComparePoints>& Q, Path pa, Point *pt, char dir){
    if(pt->value == '.')                     { Q.push(Path(pa, pt, dir));     }
    else if(pt->value == '*')                { Q.push(Path(pa, pt, dir, pa.B.find(pt) == pa.B.end()));  }
    else if(pt->value == '#' && pa.bombs > 0){ Q.push(Path(pa, pt, dir, -1)); }
}

// Member Functions
Map::Map(std::istream& stream){
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
        else if(temp != '\r'){
            tempPt = new Point(lat, lng, temp);
            tempRow.push_back(tempPt);
            lng++;
        }
    }
    /*for(size_t i = 0; i < grid.size(); i++){
        for(size_t j = 0; j < grid[0].size(); j++){
            std::cout << grid[i][j]->value;
        }
        std::cout << std::endl;
    }*///
}
Map::~Map(){
    for(size_t i = 0; i < grid.size(); i++){
        for(size_t j = 0; j < grid[0].size(); j++){
            delete grid[i][j];
        }
    }
}

std::string Map::route(Point src, Point dst){
    if(!isValid(src) || grid[src.lat][src.lng]->value == '#' || grid[src.lat][src.lng]->value == '~'){ 
                       throw PointError(src); } // Check Start
    if(!isValid(dst)){ throw PointError(dst); } // Check End

    // Variables
    std::priority_queue<Path, std::vector<Path>, ComparePoints> Q;
    std::unordered_map<Point*, int> searched;
    Point *current = grid[src.lat][src.lng], *index;
    char dir[4] = {'n','e','s','w'};
    
    // Initialize
    current->setMag(dst);
    Q.push(Path(current));
    Path temp = Q.top();
    searched[current] = temp.bombs;

    while(!(*current == dst && temp.bombs >= 0) && !Q.empty()){
        Q.pop();
        for(size_t i = 0; i < 4; i++){
            index = current;
            if(move(index, dir[i])){
                auto pair = searched.find(index);
                if(pair == searched.end()){
                    index->setMag(dst);
                    checkPath(Q, temp, index, dir[i]);
                    searched.insert({index, temp.bombs + (index->value == '*') - (index->value == '#')});
                }
                else if(pair->second < temp.bombs + (index->value == '*') - (temp.B.find(pair->first) != temp.B.end())){
                    index->setMag(dst);
                    checkPath(Q, temp, index, dir[i]);
                    searched.at(index) = temp.bombs + (index->value == '*') - (temp.B.find(pair->first) != temp.B.end());
                }
            }
        }
        temp = Q.top();
        current = temp.pt;
    }
    
    if(Q.empty()){ throw RouteError(src, dst); } // no Route found
    else{          return Q.top().dir;         } // Route found
}

bool Map::isValid(int lat, int lng){
    if(lat < 0 || lat >= int(grid.size()) || lng < 0 || lng >= int(grid[0].size())){ return false; }
                                                                                     return true;
}
bool Map::isValid(const Point &pt){
    if(pt.lat < 0 || pt.lat >= int(grid.size()) || pt.lng < 0 || pt.lng >= int(grid[0].size())){ return false; }
                                                                                                 return true;
}
