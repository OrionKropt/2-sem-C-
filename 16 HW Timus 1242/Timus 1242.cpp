// 1242. Оборотень

#include <iostream>

#include <string>
#include <vector>
#include <queue>

using namespace std;



class Graph
{
public:
    Graph()
    {
        int n;
        
        cin >> n;
        cin.get();
        size = n;
        kids = new bool* [n];
        parents = new bool* [n];
        for (int i = 0; i < n; ++i)
        {
            kids[i] = new bool[n] {0};
            parents[i] = new bool[n] {0};
        }
        used = new bool[n] {0};

        string str;
        getline(cin, str);

        int a, b;
        while (str != "BLOOD") {

            a = atoi(str.substr(0, str.find(' ')).c_str());
            b = atoi(str.substr(str.find(' ') + 1, 100).c_str());

            kids[a - 1][b - 1] = true;
            parents[b - 1][a - 1] = true;

            getline(cin, str);
        }
    }

    void bfs(int top, bool flag) // 0 - kids 1 - parents
    {
        bool** adj = (flag) ? parents : kids;
        queue<int> q;
        used[top] = true;
        q.push(top);

        while (!q.empty()) {
            top = q.front();
            q.pop();
            for (int i = 0; i < size; ++i) {
                if (adj[top][i] && !used[i]) {
                    used[i] = true;
                    q.push(i);
                }
            }
        }
    }

    void ans()
    {
        int k = 0;
        for (int i = 0; i < size; ++i) {
            if (!used[i]) {
                cout << i + 1 << ' ';
                k++;
            }
        }
        if (!k) {
            cout << 0 << endl;
        }
    }

private:
    bool** kids;
    bool** parents;
    bool* used;
    int size;
};

int main() {

    Graph graph;
    int temp ;
 
    while (cin >> temp) {
        graph.bfs(temp - 1, 0);
        graph.bfs(temp - 1, 1);
    }
    graph.ans();

    return 0;
}
