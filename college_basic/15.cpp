#include <iostream>
#include <queue>
using namespace std;

int drow[4] = {-1, 0, 1, 0};
int dcol[4] = {0, 1, 0, -1};

int map[101][101];
bool visit[101][101];

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char tmp;
            cin >> tmp;
            map[i][j] = tmp - 48;
        }
    }
    
    queue<pair<int, int> > Q;
    Q.push({1, 1});
    visit[1][1] = true;
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        int row = cur.first;
        int col = cur.second;
        for (int i = 0; i < 4; ++i) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (0 < nrow && nrow <= n && 0 < ncol && ncol <= m) {
                if (!visit[nrow][ncol] && map[nrow][ncol]) {
                    visit[nrow][ncol] = true;
                    map[nrow][ncol] = map[row][col] + 1;
                    Q.push({nrow, ncol});
                }
            }
        }
    }

    int res = map[n][m];
    cout << res << endl;
    return 0;
}