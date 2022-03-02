#include <iostream>
using namespace std;

int n, k;
int value[101];
int dp[100001];

int main() 
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= k; ++i) dp[i] = 100001;
    for (int i = 1; i <= n; ++i) {
        cin >> value[i];
        dp[value[i]] = 1;
    }
     
    for (int i = 1; i <= n; ++i) {
        for (int j = value[i]; j <= k; ++j) {    
            dp[j] = min(dp[j], dp[j - value[i]] + 1);
        }
    }

    if (dp[k] == 100001) cout << -1 << '\n';
    else cout << dp[k] << '\n';

    return 0;
}