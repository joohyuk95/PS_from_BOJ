#include <iostream>
using namespace std;

int n, m;
int dp[1001][1001];

int drow[3] = {-1, 0, -1};
int dcol[3] = {0, -1, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> dp[i][j];
            int max = 0;
            for (int k = 0; k < 3; ++k) {
                int cur = dp[i + drow[k]][j + dcol[k]];
                if (cur > max) max = cur;
            }
            dp[i][j] += max;
        }
    }

    cout << dp[n][m] << '\n';
    return 0;
}