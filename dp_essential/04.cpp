#include <iostream>
using namespace std;

int n, res;
int dp[1001][10];

int main()
{
    cin >> n;
    for (int i = 0; i < 10; ++i) dp[1][i] = 1;
    
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (j == 0) {
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            dp[i][j] %= 10007;
        }
    }

    for (int i = 0; i < 10; ++i) {
        res += dp[n][i];
    }
    cout << res % 10007 << '\n';
    return 0;
}