#include <iostream>
#include <queue>
#include <vector>
#define INF 100000
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int t, n, m, a, b, c;
    queue<int> Q;
    cin >> t;
    for (int p = 1; p <= t; ++p) {
        cin >> n >> m;
        vector<vector<int> > map(n+1, vector<int> (n+1, INF));
        for (int i = 1; i <= m; ++i) {
            cin >> a >> b >> c;
            map[a][b] = c;
            map[b][a] = c;
        }
        for (int i = 1; i <= n; ++i) map[i][i] = 0;
        for (int q = 1; q <= n; ++q) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    map[i][j] = min(map[i][j], map[i][q] + map[q][j]);
                }
            }
        }

        int k, mini = INF, idx;
        cin >> k;
        vector<int> sum(n+1);
        for (int i = 1; i <= k; ++i) {
            cin >> a;
            for (int j = 1; j <= n; ++j) {
                sum[j] += map[a][j];
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (sum[i] < mini) {
                mini = sum[i];
                idx = i;
            }
        }
        Q.push(idx);
    }

    while (!Q.empty()) {
        cout << Q.front() << endl;
        Q.pop();
    }
    return 0;
}