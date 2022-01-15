#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int drow[4] = {0, 1, 0, -1};
int dcol[4] = {1, 0, -1, 0};

int main()
{
    ios_base::sync_with_stdio(false);
    int m, n, k;
    cin >> m >> n >> k;
    vector<vector<bool> > map(m, vector<bool> (n));
    for (int p = 1; p <= k; ++p) {
        int c1, r1, c2, r2; cin >> c1 >> r1 >> c2 >> r2;
        for (int i = r1; i < r2; ++i) {
            for (int j = c1; j < c2; ++j) {
                if (!map[i][j]) map[i][j] = true;
            }
        }
    }

    int cnt = 0;
    queue<pair<int, int> > Q;
    priority_queue<int> pq;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!map[i][j]) {
                cnt++;
                Q.push({i, j});
                map[i][j] = true;

                int local_cnt = 0;
                while (!Q.empty()) {
                    local_cnt++;
                    auto cur = Q.front(); Q.pop();
                    int row = cur.first;
                    int col = cur.second;

                    for (int k = 0; k < 4; ++k) {
                        int nrow = row + drow[k];
                        int ncol = col + dcol[k];
                        if (nrow < 0 || nrow >= m || ncol < 0 || ncol >= n) continue;
                        if (!map[nrow][ncol]) {
                            map[nrow][ncol] = true;
                            Q.push({nrow, ncol});
                        }
                    }
                }
                pq.push(-local_cnt);
            }
        }
    }
    cout << cnt << endl;
    while (!pq.empty()) {
        cout << -pq.top() << ' ';
        pq.pop();
    }
    cout << endl;
    return 0;
}