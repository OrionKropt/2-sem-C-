#include <iostream>

using namespace std;




/// 
/// Timus 2099
/// 
///
/// векторы должны быть в одной плоскости
/// перпендикулярны
/// C и D лежат с одной стороны от плосокости 
/// правильный порядок точек A -> B -> C -> D  
/// 
/// ДЗ Дописать Паша
/// 
/// Спроектировтаь класс игры любой Макс
/// 
/// Расскзать что такое Конструтор копирвоания и оператор присваивания Костян
///  
/// 



class Point
{
public:
	Point(long long x = 0, long long y = 0, long long z = 0) { this->x = x; this->y = y; this->z = z; }
	Point operator-(const Point& other)
	{
		return Point(this->x - other.x, this->y - other.y, this->z - other.z);
	}
	long long ScallorProdauct(const Point& other)
	{
		return this->x * other.x + this->y * other.y + this->z * other.z;
	}

	Point operator*(const Point& other)
	{
		return Point(this->y * other.z - this->z * other.y, this->z * other.x - this->x * other.z, this->x * other.y - this->y * other.x);
	}

	bool IsComple(Point& B, Point& C, Point& D)  // смешанное произведение == 0
	{
		return !((D - *this).ScallorProdauct((B - *this) * (C - *this)));
	}

	long long x;
	long long y;
	long long z;
};

class Plane{
public:
	Plane(long long A1, long long B1, long long C1, long long D1) :
		A(A1), B(B1), C(C1), D(D1) {}
	//Plane(long long A, long long B, long long C, long long D) { this->A = A; this->B = B; this->C = C; this->D = D; }
	Plane() {}
	Plane(const Point& n, const Point& O)
	{
		A = n.x;
		B = n.y;
		C = n.z;
		D = -A * O.x - B * O.y - C * O.z;
	}

	Plane(const Point& a, const Point& b, const Point& c)
	{
		return Plane((b - a) * (c - a), c);
	}
	long long A;
	long long B;
	long long C;
	long long D;
};


int main()
{


	return 0;     
}