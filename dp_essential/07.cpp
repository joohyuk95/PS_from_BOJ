#include <iostream>
using namespace std;

int n;
int map[101][101];
long long dp[101][101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> map[i][j];
        }
    }

    dp[1][1] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == n && j == n) break;
            if (dp[i][j]) {
                int nrow = i + map[i][j];
                int ncol = j + map[i][j];

                if (nrow <= n) dp[nrow][j] += dp[i][j];
                if (ncol <= n) dp[i][ncol] += dp[i][j];
            }
        }
    }

    cout << dp[n][n] << '\n';
    return 0;
}