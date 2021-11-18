#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#define INF 100
using namespace std;
bool res[51];

int main()
{
    ios_base::sync_with_stdio(false);
    int t, n, x, y;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> n;
        vector<int> map[103];
        vector<pair<int, int> > loc(n+3);
        for (int j = 1; j <= n+2; ++j) {
            cin >> x >> y;
            loc[j] = (make_pair(x, y));
        }
        for (int j = 1; j <= n+1; ++j) {
            for (int k = j+1; k <= n+2; ++k) {
                int x1 = loc[j].first, y1 = loc[j].second;
                int x2 = loc[k].first, y2 = loc[k].second;
                int d = abs(x1-x2) + abs(y1-y2);
                if (d <= 1000) {
                    map[j].push_back(k);
                    map[k].push_back(j);
                }
            }
        }

        queue<int> Q;
        vector<int> ch(n+3);
        vector<int> dist(n+3, INF);
        Q.push(1);
        ch[1] = 1;
        while (!Q.empty()) {
            int tmp = Q.front(); Q.pop();
            for (int j = 0; j < map[tmp].size(); ++j) {
                if (!ch[map[tmp][j]]) {
                    ch[map[tmp][j]] = 1;
                    Q.push(map[tmp][j]);
                    dist[map[tmp][j]] = dist[tmp] + 1;
                }
            }
        }
        if (dist[n+2] == INF) res[i] = false;
        else res[i] = true;
    }
    for (int i = 1; i <= t; ++i) {
        if (res[i]) cout << "happy" << endl;
        else cout << "sad" << endl;
    }
    return 0;
}