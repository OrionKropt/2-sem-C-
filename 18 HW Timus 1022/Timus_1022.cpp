#include <iostream>
#include <vector>
#include <stack>




using namespace std;



class Graph 
{
public:
    Graph() 
    {
        cin >> size;
        size += 1;
        gr = vector<vector<int>>(size);
        used = new bool[size] {0};
        int a = 0;
        int i = 1;
        while (i < size)
        { 
            cin >> a;
            if (a == 0)
                ++i;
            else
                gr[i].push_back(a);
        }
    }

    void top_sort()
    {
        for (int i = 1; i < size; ++i)
        {
            if (!used[i])
                top_sort(i);
        }
    }

    void top_sort(int v)
    {
        used[v] = true;
        for (auto a : gr[v])
        {
            if (!used[a])
                top_sort(a);
        }
        res.push(v);
    }

    void ans()
    {
        while (!res.empty()) 
        {
            cout << res.top() << ' ';
            res.pop();
        }
    }

   
private:
    int size;
    vector<vector<int>> gr;
    bool* used;
    stack<int> res;
};

int main() 
{
    Graph graph;
    graph.top_sort();
    graph.ans();
}