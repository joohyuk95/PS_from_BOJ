#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int tc, m, n, k;

int drow[4] = {1, 0, -1, 0};
int dcol[4] = {0, 1, 0, -1};
queue<int> res;

int main()
{
    cin >> tc;
    for (int p = 1; p <= tc; ++p) {
        cin >> m >> n >> k;
        vector<vector<bool> > map(n, vector<bool> (m));
        vector<vector<bool> > visit(n, vector<bool> (m));
        for (int i = 1; i <= k; ++i) {
            int x, y; cin >> x >> y;
            map[y][x] = true;
        }
        
        int cnt = 0;
        queue<pair<int, int> > Q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!visit[i][j] && map[i][j]) {
                    cnt++;
                    visit[i][j] = true;
                    Q.push({i, j});
                    while (!Q.empty()) {
                        auto cur = Q.front(); Q.pop();
                        int row = cur.first;
                        int col = cur.second;
                        for (int l = 0; l < 4; ++l) {
                            int nrow = row + drow[l];
                            int ncol = col + dcol[l];
                            if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= m) continue;
                            if (!visit[nrow][ncol] && map[nrow][ncol]) {
                                visit[nrow][ncol] = true;
                                Q.push({nrow, ncol});
                            }
                        }
                    }
                }
            }
        }
        res.push(cnt);
    }

    while (!res.empty()) {
        cout << res.front() << endl;
        res.pop();
    }
    return 0;
}