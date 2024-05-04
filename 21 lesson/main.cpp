#include <iostream>
#include <cmath>

using namespace std;


// ДЗ
// 1. Напсать класс прямая. Нужно проверить паралеьны они, совпадаеют или перемекаются,
// если пересекаются то вернуть точку пересечения
// В классе должен быть метод который возвращает точку пересечения, через пердачу по ссылке  Тихонов
// 2. Рассказать про умыне указатели на флешке будет жоска все написано надо все расскзать это мне
//
// 3. Решить уравнение. у нас есть функция надо найти точку в торой занчение равно 0 по теореме Веиштрасса
//


double intel();

double f(double x) { return sin(x); }

double Square(double(*) (double), double, double, double);



int main()

{
	double a, b, h;
	cin >> a >> b >> h;
	cout << Square(f, a, b, h);


/*
	for (i)
		for(j)
			for(k)
				for(t)
					for(h)
						for(r)
							for(c)
								for(f)
							for (c)
						for (r)
					for (h)
				for (t)
			for (k)
		for (j)
	for (i)
*/


	// интегралл почситаь функцию в функцию передаем
	// задаем ширину полоски и счаитем длины всех полосок
	// Тимус Ананас  (страшный не надо его делать)
	return 0;
}

double Square(double (*F) (double x), double a, double b, double h)
{
	double sum = (F(a) + F(b)) / 2;
	for (double i = a; i <= b; i += h)
	{
		sum += F(a);
	}
	return sum * h;
}