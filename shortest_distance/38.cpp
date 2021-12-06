#include <iostream>
#include <vector>
#include <queue>
#define INF 32000
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int> > map(n+1, vector<int> (n+1, INF));
    for (int i = 1; i <= m; ++i) {
        int u, v, b; cin >> u >> v >> b;
        map[u][v] = 0;
        map[v][u] = (b) ? 0 : 1;
    }
    for (int i = 1; i <= n; ++i) map[i][i] = 0;
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }

    int k;
    queue<int> Q;
    cin >> k;
    for (int i = 1; i <= k; ++i) {
        int s, e; cin >> s >> e;
        Q.push(map[s][e]);
    }

    while (!Q.empty()) {
        cout << Q.front() << '\n';
        Q.pop();
    }
    return 0;
}