#include <iostream>
#include <vector>
using namespace std;

int t, n;
int dp[41][2];

int main()
{
    ios_base::sync_with_stdio(false);
    
    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = 1;

    for (int i = 2; i <= 40; ++i) {
        dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
        dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
    }
    
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> n;
        cout << dp[n][0] << ' ' << dp[n][1] << '\n'; 
    }

    return 0;
}