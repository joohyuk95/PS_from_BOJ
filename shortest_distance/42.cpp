#include <iostream>
#include <vector>
#define INF 10000000
using namespace std;

int map[101][101];
int cross[101][101];
vector<int> path; 

void Path_DFS(int start, int end)
{
    if (cross[start][end] == 0) {
        path.push_back(start);
        path.push_back(end);
        return;
    }
    Path_DFS(start, cross[start][end]);
    path.pop_back();
    Path_DFS(cross[start][end], end);
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;
            else map[i][j] = INF;
        }
    }
    for (int i = 1; i <= m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        map[a][b] = (map[a][b] < c) ? map[a][b] : c;
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (map[i][j] > map[i][k] + map[k][j]) {
                    map[i][j] = map[i][k] + map[k][j];
                    cross[i][j] = k;
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (map[i][j] == INF) cout << 0 << ' ';
            else cout << map[i][j] << ' ';
        }
        cout << '\n';
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (map[i][j] == INF || i == j) cout << 0;
            else {
                path.clear();
                Path_DFS(i, j);
                cout << path.size() << ' ';
                for (int k = 0; k < path.size(); ++k) {
                    cout << path[k] << ' ';
                }
            }
            cout << '\n';
        }        
    }

    return 0;
}