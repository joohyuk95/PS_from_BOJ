#include <iostream>
#define MOD 1000000000
using namespace std;

int n, res;
int dp[101][10];

int main()
{
    cin >> n;

    for (int i = 1; i < 10; ++i) dp[1][i] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][j + 1];
            } else if (j == 9) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
            }
            dp[i][j] %= MOD;
        }
    }

    for (int i = 0; i < 10; ++i) {
        res += dp[n][i];
        res %= MOD;
    }
    cout << res << '\n';
    return 0;
}