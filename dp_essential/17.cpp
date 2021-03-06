#include <iostream>
#define MOD 1000000000
using namespace std;

int n, k;
long long dp[201][201];

int main()
{
    cin >> n >> k;
    for (int i = 0; i <= n; ++i) {
        dp[1][i] = 1;
    }
    
    for (int i = 2; i <= k; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int p = 0; p <= j; ++p) {
                dp[i][j] += dp[i - 1][p];
            }
            dp[i][j] %= MOD;
        }
    }
    
    cout << dp[k][n] << '\n';
    return 0;
}