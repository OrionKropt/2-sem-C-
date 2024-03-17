#pragma once

#include <iostream>
#include <cmath>

using namespace std;

class Point {
public:
    Point();
    Point(double, double);
    Point(const Point&);

    static double Distance(const Point&, const Point&);
    void Print() const;
    double GetX() const;
    double GetY() const;
    Point& operator=(const Point&);
    bool operator==(const Point&);

private:
    double x;
    double y;
};

Point::Point(): x(), y() {}
Point::Point(double X, double Y): x(X), y(Y) {}
Point::Point(const Point& other): x(other.x), y(other.y) {}

double Point::Distance(const Point& A, const Point& B) {
    return sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y));
}

void Point::Print() const {
    cout << '(' << x << "; " << y << ')' << endl;
}

double Point::GetX() const
{
    return x;
}

double Point::GetY() const
{
    return y;
}

Point& Point::operator=(const Point& other) {
    x = other.x;
    y = other.y;
    return *this;
}

bool Point::operator==(const Point& other) {
    return (x == other.x && y == other.y);
}
