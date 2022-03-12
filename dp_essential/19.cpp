#include <iostream>
using namespace std;

int n;
int cost[1001][3];
int dp[1001][3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> cost[i][j];
        }
    }
    cost[0][0] = cost[0][1] = cost[0][2] = 0;

    for (int i = 1; i <= n; ++i) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][2];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][1];
    }

    cout << min(min(dp[n][0], dp[n][1]), dp[n][2]) << '\n';
    return 0;
}