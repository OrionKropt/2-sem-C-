#pragma once

#include <iostream>
#include <cmath>
#include "point.h"

using namespace std;

class Segment {
public:
    Segment();
    Segment(const Point&, const Point&);
    Segment(double, double, double, double);
    Segment(const Segment&);

    static double DistancePointToSegment(const Point&, const Segment&);
    static int Side(const Point&, const Segment&);

    Segment& operator=(const Segment&);
    bool operator==(const Segment&);

private:
    Point A;
    Point B;
};

Segment::Segment(): A(), B() {}
Segment::Segment(const Point& First, const Point& Second): A(First), B(Second) {}
Segment::Segment(double Ax, double Ay, double Bx, double By): A(Ax, Ay), B(Bx, By) {}
Segment::Segment(const Segment& other): A(other.A), B(other.B) {}

double Segment::DistancePointToSegment(const Point& P, const Segment& S) {
    double S_length = Point::Distance(S.A, S.B);
    if (S_length == 0)  // Outgrowth of a segment to a point (length = 0)
        return Point::Distance(P, S.A);

    double t = ((P.GetX() - S.A.GetX()) * (S.B.GetX() - S.A.GetX()) + (P.GetY() - S.A.GetY()) * (S.B.GetY() - S.A.GetY())) / (S_length * S_length);
    if (t < 0)  // Toward the beginning of the segment
        return Point::Distance(P, S.A);
    if (t > 1)  // Toward the end of the segment
        return Point::Distance(P, S.B);

    Point projection = Point(S.A.GetX() + t * (S.B.GetX() - S.A.GetX()), S.A.GetY() + t * (S.B.GetY() - S.A.GetY()));
    return Point::Distance(P, projection);
}

int Segment::Side(const Point& P, const Segment& S) {  // 1 - left, -1 - right, 0 - on the segment
    double res = (P.GetX() - S.A.GetX()) * (S.B.GetY() - S.A.GetY()) - (P.GetY() - S.A.GetY()) * (S.B.GetX() - S.A.GetX());
    return res == 0 ? 0 : (res < 0 ? -1 : 1);
}

Segment& Segment::operator=(const Segment& other) {
    A = other.A;
    B = other.B;
    return *this;
}

bool Segment::operator==(const Segment& other) {
    return (A == other.A && B == other.B);
}
