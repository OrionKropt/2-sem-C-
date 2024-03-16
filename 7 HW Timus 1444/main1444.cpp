/////
/////  1. space invader Timus 2099 решить (Тяжело)
/////  
/////  2. Timus 1444 (несложно)
///// 
/////  Приводят на пле грифа а там растут тыквы с координатами
///// Мутим клас Point, Scene -> колчиство тыкв и методы для решения задачи
///// Гриф должен сьесть как можно больше, ессли он наткнулся на свои следы то алгоритм закончен
///// По факту нужно найти максимально длинную ломанную линию без самопересечения
///// 
///// Проходим по всем точкам и считаем коссинусы и сортируем в порядке возрастания
///// 
///// 3. Написать класс поленом (многочлен) над полем по модулю 3 ( коэфы 0, 1, 2)
///// В нем есть:
///// Поля:
/////		Страшая степень
/////		массив коэфицеентов
///// Методы:
/////		Print()
/////		Конструктор
/////		Ввод по коэфам (можно пропускать нулики)
/////		Вычисление значения полинома в точке
/////		Сложение двух многочленов
/////		Деление многочлена столбиком
/////		Опредление неприводимости многочлена
/////		Зашифровать с помощью многочлена текст (по-желанию)
///// 
///// 
///// 
///// 

#include <iostream>

using namespace std;




class Point
{
public:
	Point(const double& x, const double& y)
	{
		this->x = x;
		this->y = y;
	}
	Point() {}
	double GetX() const { return x; } 
	double GetY() const { return y; }

private:
	double x = 0;
	double y = 0;
};

struct Pumpkin
{
	Pumpkin(const Point& a, const int& id) : a(a), id(id) {}
	Pumpkin() {}
	Point a;
	double Sin = 2;
	double dis = 0;
	int defintion = 0;
	int id = 0;
};


void SelectionSort(Pumpkin*, int&);
class Scene
{
public:
	Scene(const int count) : count(count)
	{
		arr = new Pumpkin[count];
	}
	void Fill()
	{
		for (int i = 0; i < count; i++)
		{
			double x, y;
			cin >> x >> y;
			Point p(x, y);
			arr[i] = Pumpkin(p, i + 1);
			//cout << "X= " << arr[i].a.GetX() << " Y= " << arr[i].a.GetY() << endl;
		}
	}
	
	

	void SortSin(const Point& p)
	{
		if (abs(arr[1].Sin) >= 1)
		{
			CalculateSinAndDis(p);
			QuarterDefinition(p);
		}
		SelectionSort(arr, count);
		
	}


	Point GetStartPoint() const { return arr[0].a; }

	void ViewId()
	{
		cout << count<< endl;
		cout << arr[0].id << endl;
		for (int i = 1; i < count; ++i)
			cout << arr[i].id << endl;
		
	}

private:
	void CalculateSinAndDis(const Point& p)
	{
		
		for (int i = 1; i < count; i++)
		{
			arr[i].dis = sqrt((arr[i].a.GetX() - p.GetX()) * (arr[i].a.GetX() - p.GetX()) +
				(arr[i].a.GetY() - p.GetY()) * (arr[i].a.GetY() - p.GetY()));
			arr[i].Sin = (arr[i].a.GetY() - p.GetY()) / arr[i].dis;
			 
			//cout  << "id " << arr[i].id << ' ' << arr[i].Sin << endl;
		}
	}
	void QuarterDefinition(const Point& p)
	{
		for (int i = 1; i < count; i++)
		{
			if (arr[i].a.GetX() - p.GetX() >= 0 && arr[i].a.GetY() - p.GetY() >= 0)
				arr[i].defintion = 1;
			else if (arr[i].a.GetX() - p.GetX() <= 0 && arr[i].a.GetY() - p.GetY() >= 0)
				arr[i].defintion = 2;
			else if (arr[i].a.GetX() - p.GetX() <= 0 && arr[i].a.GetY() - p.GetY() <= 0)
				arr[i].defintion = 3;
			else
				arr[i].defintion = 4;
			cout << "id " << arr[i].id << " defintion " << arr[i].defintion << endl;
		}
	}
	int count;
	Pumpkin* arr;
};

int main()
{
	int K;
	cin >> K;
	Scene Scene(K);
	Scene.Fill();

	
	
	Scene.SortSin(Scene.GetStartPoint());
	Scene.ViewId();
	
	return 0;
}

void SelectionSort(Pumpkin* arr, int& n) // O(n^2)
{
	double eps = 1e-14;


	for (int i = 1; i < n - 1; ++i)
	{
		int pivod = i;
		for (int j = i + 1; j < n; ++j)
		{
			//if (arr[j].defintion != arr[pivod].defintion) break;
			if (arr[pivod].defintion == 1 || arr[pivod].defintion == 4)
			{
				if (arr[j].defintion == 1 || arr[j].defintion == 4)
				{
					double dx = abs(abs(arr[j].Sin) - abs(arr[pivod].Sin));
					//cout << "arr[" << j << "].dis " << arr[j].dis << " arr[" << pivod << "].dis " << arr[pivod].dis << endl;
					if (dx < eps)	
						if (arr[j].dis < arr[pivod].dis) pivod = j;
					else if (arr[j].Sin < arr[pivod].Sin) pivod = j;
					

				}
			}
			else if (arr[pivod].defintion == 2 || arr[pivod].defintion == 3)
			{
				double dx = abs(abs(arr[j].Sin) - abs(arr[pivod].Sin));
				if (dx < eps)
					if (arr[j].dis < arr[pivod].dis) pivod = j;
				else if (arr[j].Sin > arr[pivod].Sin) pivod = j;
			
			}
			else continue;
		}
		swap(arr[i], arr[pivod]);
	}
}



