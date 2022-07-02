#include <iostream>
#include <vector>
#define MAX 20001
using namespace std;

int k, v, e;
int visit[MAX];
vector<int> map[MAX];

void DFS(int start)
{
    if (visit[start] == false) visit[start] = 1;

    for (int i = 0; i < map[start].size(); ++i) {
        int next = map[start][i];
        if (!visit[next]) {
            if (visit[start] == 1) {
                visit[next] = 2;
            } else if (visit[start] == 2) {
                visit[next] = 1;
            }
            DFS(next);
        }
    }
}

bool isBigraph()
{
    for (int i = 1; i <= v; ++i) {
        for (int j = 0; j < map[i].size(); ++j) {
            int next = map[i][j];
            if (visit[i] == visit[next]) {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    cin >> k;

    for (int p = 1; p <= k; ++p) {
        cin >> v >> e;

        for (int i = 1; i <= e; ++i) {
            int a, b; cin >> a >> b;
            map[a].push_back(b);
            map[b].push_back(a);
        }

        for (int i = 1; i <= v; ++i) {
            if (!visit[i]) {
                DFS(i);
            }
        }

        if (isBigraph()) cout << "YES" << '\n';
        else cout << "NO" << '\n';

        for (int i = 0; i <= v; ++i) {
            map[i].clear();
            visit[i] = 0;
        }
    }
    return 0;
}