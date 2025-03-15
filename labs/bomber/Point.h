#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>

struct Point {
  private: 
    int lat;  // Latitude
    int lng;  // Longitude
  public:
    char value;
    int mag;

    Point() {
        lat = 0;
        lng = 0;
        value = '~';
        mag = 0;
    }

    Point(int lat, int lng, char value) {
        this->lat = lat;
        this->lng = lng;
        this->value = value;
        this->mag = findMag();
    }

    Point(const Point& other) {
        this->lat = other.lat;
        this->lng = other.lng;
        this->value = other.value;
        this->mag = findMag();
    }

    void move(int nLat, int nLng){
        this->lat = nLat;
        this->lng = nLng;
        this->mag = findMag();
    }
    int getLat() const{ return lat; }
    int getLng() const{ return lng; }

    int findMag(){
        return abs(lat) + abs(lng);
    }
};

// Operators for easier (and consistent) input and output:
std::ostream& operator << (std::ostream& stream, const Point& point);
std::istream& operator >> (std::istream& stream, Point& point);
bool operator == (const Point &p1, const Point &p2){
    return &p1 == &p2;
}
struct ComparePoints{
    bool operator()(const Point &p1, const Point &p2){
        return p1.mag > p2.mag;
    }
};

#endif
