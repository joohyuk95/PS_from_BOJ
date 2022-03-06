#include <iostream>
using namespace std;

int t, n;
int dp[11];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> t;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 1; i <= t; ++i) {
        cin >> n;
        for (int j = 4; j <= n; ++j) {
            dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
        }
        cin >> dp[n];
    }

    return 0;
}