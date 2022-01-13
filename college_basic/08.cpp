#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int cnt;

vector<int> map[101];
bool visit[101];

void DFS(int x)
{
    visit[x] = true;
    for (int i = 0; i < map[x].size(); ++i) {
        int next = map[x][i];
        if (!visit[next]) {
            DFS(next);
            cnt++;
        }
    }
}

void BFS()
{
    queue<int> Q;
    Q.push(1);
    visit[1] = true;

    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();

        for (int i = 0; i < map[cur].size(); ++i) {
            int next = map[cur][i];
            if (!visit[next]) {
                visit[next] = true;
                Q.push(next);
                cnt++;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int a, b; cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }

    // BFS();
    DFS(1);
    cout << cnt << endl;
    return 0;
}