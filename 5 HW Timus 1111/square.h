#pragma once

#include <iostream>
#include <cmath>
#include "segment.h"

class Square {
public:
    Square();
    Square(const Point&, const Point&, const unsigned int&);
    Square(double, double, double, double, const unsigned int&);
    Square(const Square&);

    void DistancePointToSquare(const Point&);
    double GetDistance() const;
    unsigned int GetId() const;
private:
    Segment* sides;
    double dis;
    unsigned int id;
};

Square::Square(): sides(nullptr), dis(0), id(0) {}
Square::Square(const Point& A, const Point& C, const unsigned int& id) {
    double x_center = (A.GetX() + C.GetX()) / 2, y_center = (A.GetY() + C.GetY()) / 2;
    Point B = Point(x_center + (C.GetY() - A.GetY())/2, y_center - (C.GetX() - A.GetX())/2);
    Point D = Point(x_center - (C.GetY() - A.GetY())/2, y_center + (C.GetX() - A.GetX())/2);

    sides = new Segment[4] {
        Segment(A, B),
        Segment(B, C),
        Segment(C, D),
        Segment(D, A)
    };
    this->dis = 0;
    this->id = id;
}
Square::Square(double Ax, double Ay, double Cx, double Cy, const unsigned int& id) {
    Point A = Point(Ax, Ay);
    Point C = Point(Cx, Cy);

    double x_center = (A.GetX() + C.GetX())/2, y_center = (A.GetY() + C.GetY())/2;
    Point B = Point(x_center + (C.GetY() - A.GetY())/2, y_center - (C.GetX() - A.GetX())/2);
    Point D = Point(x_center - (C.GetY() - A.GetY())/2, y_center + (C.GetX() - A.GetX())/2);

    sides = new Segment[4] {
            Segment(A, B),
            Segment(B, C),
            Segment(C, D),
            Segment(D, A)
    };
    this->dis = 0;
    this->id = id;
}
Square::Square(const Square& other) {
    sides = new Segment[4] {
        other.sides[0],
        other.sides[1],
        other.sides[2],
        other.sides[3]
    };
    this->dis = other.dis;
    this->id = other.id;
}

void Square::DistancePointToSquare(const Point& P) {
    if (
        Segment::Side(P, this->sides[0]) < 0 &&
        Segment::Side(P, this->sides[1]) < 0 &&
        Segment::Side(P, this->sides[2]) < 0 &&
        Segment::Side(P, this->sides[3]) < 0
       ) dis =  0;
    else dis = min(
               min(Segment::DistancePointToSegment(P, this->sides[0]),
                   Segment::DistancePointToSegment(P, this->sides[1])),
               min(Segment::DistancePointToSegment(P, this->sides[2]),
                   Segment::DistancePointToSegment(P, this->sides[3]))
           );
}

double Square::GetDistance() const
{
    return dis;
}

inline unsigned int Square::GetId() const
{
    return id;
}
