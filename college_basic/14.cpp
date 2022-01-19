#include <iostream>
#include <queue>
using namespace std;

int m, n, res;
bool flag = true;

int drow[4] = {-1, 0, 1, 0};
int dcol[4] = {0, 1, 0, -1};

int map[1001][1001], day[1001][1001];
queue<pair<int, int> > Q;

int main()
{
    ios_base::sync_with_stdio(false);
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> map[i][j];
            if (map[i][j] == 1) Q.push({i, j});
            if (map[i][j] == 0) flag = false;
        }
    }
    if (flag) {
        cout << 0 << endl;
        exit(0);
    }

    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        int row = cur.first;
        int col = cur.second;

        for (int i = 0; i < 4; ++i) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (0 < nrow && nrow <= n && 0 < ncol && ncol <= m) {
                if (map[nrow][ncol] == 0) {
                    map[nrow][ncol] = 1;
                    day[nrow][ncol] = day[row][col] + 1;
                    Q.push({nrow, ncol});
                }
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (map[i][j] == 0) {
                cout << -1 << endl;
                exit(0);
            }
            if (day[i][j] > res) res = day[i][j];
        }
    }
    cout << res << endl;
    return 0;
}