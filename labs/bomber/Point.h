#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>

struct Point {
    int lat;  // Latitude
    int lng;  // Longitude
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
        this->mag = 0;
    }

    Point(const Point& other) {
        this->lat = other.lat;
        this->lng = other.lng;
        this->value = other.value;
        this->mag = 0;
    }

    void setMag(const Point &dst){
        mag = abs(lat-dst.lat) + abs(lng-dst.lng);
    }
};

// Operators for easier (and consistent) input and output:
std::ostream& operator << (std::ostream& stream, const Point& point);
std::istream& operator >> (std::istream& stream, Point& point);
bool operator == (const Point& pt1, const Point& pt2);
bool operator != (const Point& pt1, const Point& pt2);


#endif
