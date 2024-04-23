#include <iostream>
#include <vector>





using namespace std;



class Graph
{
public:
    Graph()
    {
        int m;
        cin >> size >> m;
        size += 1;
        gr = vector<vector<int>>(size);
        guess = new int[size] {0};
        for (int i = 0; i < m; ++i)
        {
            int a = -1, b = -1;
            cin >> a >> b;
            gr[a].push_back(b);
        }
        for (int i = 1; i < size; ++i)
            cin >> guess[i];
        
    }


    void ans()
    {
        for (int i = 1; i < size; ++i)
            for (int j = i + 1; j < size; ++j)
            {
                for (auto a : gr[guess[j]])
                {
                    if (a == guess[i])
                    {
                        cout << "NO";
                        return;
                    }
                }
            }
        cout << "YES";
    }

   
private:
    int size;
    vector<vector<int>> gr;
    int* guess;
};

int main()
{
    Graph graph;
    graph.ans();
}