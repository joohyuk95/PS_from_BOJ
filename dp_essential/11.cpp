#include <iostream>
using namespace std;
#define MAX 100001

int n, ans;
int seq[MAX];
int dp[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> seq[i];

    dp[1] = seq[1];
    ans = dp[1];
    for (int i = 2; i <= n; ++i) {
        dp[i] = seq[i];
        if (dp[i] < dp[i - 1] + seq[i]) {
            dp[i] = dp[i - 1] + seq[i];
        }
        if (dp[i] > ans) ans = dp[i];
    }

    cout << ans << '\n';
    return 0;
}