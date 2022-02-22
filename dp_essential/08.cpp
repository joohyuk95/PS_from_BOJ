#include <iostream>
using namespace std;

int m, n, cnt;
int map[501][501];
int dp[501][501];

int drow[4] = {-1, 0, 1, 0};
int dcol[4] = {0, 1, 0, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> map[m][n];
        }
    }

    dp[1][1] = 1;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 0; k < 4; ++k) {
                int nrow = i + drow[k];
                int ncol = j + dcol[k];
                if (ncol == 0 || nrow == 0) continue;
                if (i == m && j == n) break;
                if (map[nrow][ncol] < map[i][j]) {
                    dp[nrow][ncol] += dp[i][j];
                }
            }
        }
    }

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << dp[m][n] << '\n';
    return 0;
}