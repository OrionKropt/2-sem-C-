#include <iostream>
#include <cmath>
#include "square.h"

using namespace std;


void HoareSort(Square*&, const int&, const int&);
void ExtraCondition(Square*&, const int&);
int main() {
    int n;
    cin >> n;
    Square* squares = new Square[n];
 

    int Ax, Ay, Cx, Cy;
    for (int i = 0; i < n; ++i) {
        cin >> Ax >> Ay >> Cx >> Cy;
        squares[i] = Square(Ax, Ay, Cx, Cy, i+1);
    }

    cin >> Ax >> Ay;
    Point P = Point(Ax, Ay);

    for (int i = 0; i < n; ++i)
        squares[i].DistancePointToSquare(P);
      
   
    HoareSort(squares, 0, n - 1);
    ExtraCondition(squares, n);
    for (int i = 0; i < n; ++i)
        cout << squares[i].GetId() << ' ';

 

    return 0;
}



void HoareSort(Square*& arr, const int& left, const int& right) // O(n log(n))
{
    int l = left;
    int r = right;
    double mid = arr[(l + r) / 2].GetDistance();
    do
    {
        while (arr[l].GetDistance() < mid)
            ++l;

        while (arr[r].GetDistance() > mid)
            --r;

        if (l <= r)
        {
            swap(arr[l], arr[r]);
            ++l;
            --r;
        }
    } while (l < r);

    if (left < r)
        HoareSort(arr, left, r);

    if (l < right)
        HoareSort(arr, l, right);
}


void ExtraCondition(Square*& arr, const int& n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) 
             if (arr[j].GetDistance() == arr[j+1].GetDistance() && arr[j].GetId() > arr[j + 1].GetId()) swap(arr[j], arr[j+1]);
    }
}





