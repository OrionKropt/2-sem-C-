#include <iostream>
#include <cmath>
#include "square.h"

using namespace std;


void HoareSort(Square*&, const int&, const int&, bool);
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
      
   
    HoareSort(squares, 0, n - 1, 0);
    ExtraCondition(squares, n);
    for (int i = 0; i < n; ++i)
        cout << squares[i].GetId() << ' ';

 

    return 0;
}



void HoareSort(Square*& arr, const int& left, const int& right, bool data_type) // 0 - distance 1 - id
{
    if (left >= right) return;
    int l = left;
    int r = right;
    double mid = (data_type) ? arr[(l + r) / 2].GetId() : arr[(l + r) / 2].GetDistance();
    do
    {
        if (data_type)
            while (arr[l].GetId() < mid)
                ++l;
        else
            while (arr[l].GetDistance() < mid)
                ++l;

        if (data_type)
            while (arr[r].GetId() > mid)
                --r;
        else
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
        HoareSort(arr, left, r, data_type);

    if (l < right)
        HoareSort(arr, l, right, data_type);
}



void ExtraCondition(Square*& arr, const int& n) {
    for (int i = 0; i < n - 1; ++i) {
        int j = i + 1;
        while (j < n && arr[j].GetDistance() == arr[i].GetDistance())
            ++j;
        HoareSort(arr, i, j - 1, 1);
        i = j - 1;
    }
}





