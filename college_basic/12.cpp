#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n, m, v;
int map[1001][1001];
bool visit[1001];
queue<int> Q1;
queue<int> Q2;

void DFS(int x)
{
    Q1.push(x);
    visit[x] = true;
    for (int i = 1; i <= n; ++i) {
        if (map[x][i] && !visit[i]) {
            DFS(i);
        }
    }
}

void BFS(int x)
{
    queue<int> BFS_Q;
    visit[x] = true;
    BFS_Q.push(x);
    while (!BFS_Q.empty()) {
        int cur = BFS_Q.front(); BFS_Q.pop();
        Q2.push(cur);
        for (int i = 1; i <= n; ++i) {
            if (map[cur][i] && !visit[i]) {
                visit[i] = true;
                BFS_Q.push(i);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> v;
    for (int i = 1; i <= m; ++i) {
        int a, b; cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }
    DFS(v);
    memset(visit, false, sizeof(visit));
    BFS(v);

    while (!Q1.empty()) {
        cout << Q1.front() << ' ';
        Q1.pop();
    }
    cout << endl;
    while (!Q2.empty()) {
        cout << Q2.front() << ' ';
        Q2.pop();
    }
    cout << endl;
    return 0;
}