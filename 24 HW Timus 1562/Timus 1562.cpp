#include <iostream>
#include <cmath>
#include <iomanip>



using namespace std;

double PI = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798;



double Integral(double a, double b)
{
	
	return abs(b * (1 - b * b / 3) - (a * (1 - a * a / 3)));
}
int main()
{
	double a = 0, b = 0, n = 0;
	cin >> a >> b >> n;
	double step = 2 / n;
	double cur = 1;



	double k = a * a * b * PI / 8;
	double* arr = new double[n + 1];
	for (int i = 0; i <= n; ++i)
	{
		arr[i] = cur;
		cur -= step;
		//cout << arr[i] << endl;
	}

	//cout << endl;

	for (int i = 1; i <= n; ++i)
	{
		cout << fixed << setprecision(6) << Integral(arr[i - 1], arr[i]) * k << endl;
	}

	return 0;
}