#include <iostream>
#include <queue>
using namespace std;

// “имус Ќить в лабиринте BFS граф

// ѕоиск в ширину (англ. breadth-first search)


// —руктура точки
// поумолчанию x = -1 чтобы в алгоритме не работать с лишними точками 
// x и y будут соответвовать индексам массива 
struct Point
{
	Point(const int& X, const int& Y) : x(X), y(Y) {}
	Point() : x(-1), y(-1) {}
	int x;
	int y;
};

// √раф
class Graph
{
public:
	Graph(const int& Rows, const int& Cols, bool** maze) : rows(Rows), cols(Cols)
	{
		used = new bool* [rows]; 
		dis = new int* [rows];
		points = new Point[rows * cols];
		for (int i = 0; i < rows; ++i)
		{
			dis[i] = new int[cols] {0};
			used[i] = new bool[cols] {0};
			int size_byts = sizeof(bool) * cols;
			memcpy_s(used[i], size_byts, maze[i], size_byts);  // Ёта функци€ запон€лн€ет маассив used числом -1, работает за O(logN)
		}

		
		
		size_points = 0; // счеткичк дл€ подсчета количества свободных точек

		for (int i = 0; i < rows; ++i)
			for (int j = 0; j < cols; ++j)
			{
				if (maze[i][j] == 0)
					points[size_points++] = Point(i, j);
				else
					used[i][j] = 1;
			}

	}


	Point get_first_point() { return points[0]; } 
	

	int bfs(const Point& in, Point& out)
	{
		if (in.x == -1) return 0;  // ≈сли свободных точек нет, то пора выходить
		queue<Point> q;
		int Max = 0;               // «десь будет длинна пути
		q.push(in);
		used[in.x][in.y] = 1;	
		
		
		while (!q.empty())
		{
			Point p = q.front();
			out = p;
			// ¬ цикле рассматриваем все близлежщие точки
			for (auto temp : { Point(-1, 0), Point(1, 0), Point(0, -1), Point(0, 1)})
			{
				int x = p.x + temp.x, y = p.y + temp.y;
				if (x < rows && y < cols && x >= 0 && y >= 0) // ѕ–оверка на выход за границы массива 
				{
					// ≈сли еще не были в этой точке
					if (used[x][y] == 0 && dis[x][y] == 0)  
					{
						// “ак как перемещатьс€ мы можем только на 1, дистанци€ всегда увеличиваетс€ на 1
						dis[x][y] = dis[p.x][p.y] + 1;
						used[x][y] = 1;
						if (dis[x][y] > Max) Max = dis[x][y];
						//  аждую новую точку нужно закинуть в очередь, чтобы проверить, есть ли у нее соседи
						q.push(Point(x, y));
					}
				}
			}
			q.pop();
		}
		// «десь можно нагл€дно посмтреть работу bfs
	/*	for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
				cout << dis[i][j] << ' ';
			cout << endl;
		}*/
		return Max;
	}

	// ”бираемс€ за собой 
	~Graph()
	{
		for (int i = 0; i < rows; ++i) 
			delete[] dis[i];
		delete[] dis;
		delete[] points;
		for (int i = 0; i < rows; ++i)
			delete[] used[i];
		delete[] used;
	}
private:
	Point* points; // здесь хран€тс€ точки по которым можно ходить
	bool** used;   // массив лабиринта стена поумолчанию равна 1 
	int** dis;     // массив в котором харнитс€ расто€ние от начальной точки до текущей
				   // ѕример
	//         dis: если начинать поиск с точки (2, 2)
	// ####     0000
	// #..#		0010
	// ##.#		0020
	// ##..		0034
	// ####		0000
	//

	int rows;   // размеры лабиринта 
	int cols;
	int size_points; // количество свободных точек
};

int main()
{
	int n = 1, m = 1;
	cin >> n >> m;
	bool** maze = new bool*[m];
	for (int i = 0; i < m; ++i)
		maze[i] = new bool[n] {0}; 
	
	// создаем лабирнт из нулей и единиц
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
		{
			char pars = ' ';
			cin >> pars;
			switch (pars)
			{
			case '#':
				maze[i][j] = 1;
				break;
			case '.':
				maze[i][j] = 0;
				break;
			default:
				break;
			}
		}
		
	
	// создаем два графа и делаем поиск ширину
	// “ут можно было сделать по интерснее и не пересоздаевать один, но и так сойдет
	// bfs(Point a, Point b) прнимает две точки, a - это начальна€ точка, b -  выходной параметр и возварщает длинну пути
	// после вызова метода в b будет лежать сама€ дальн€€ точка 
	// 

	Graph graph(m, n, maze);
	Graph graph1(m, n, maze);
	Point first = graph.get_first_point(), second;
	// ¬ первом проходе мы берем любую точку и ищем самую дальнюю 
	graph.bfs(first, second);
	// ¬о втором проходе мы находим ширину графа и ответ на задачу
	// “оесть находим самый короткий путь от двух самых дальних точек
	cout << graph1.bfs(second, first) << endl;
	return 0;
}