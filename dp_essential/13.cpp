#include <iostream>
using namespace std;

int n;
int pack[1001];
int dp[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> pack[i];
    // dp[i] : i개의 카드를 구입하기 위한 비용의 최댓값.

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int prev = j - pack[i];
            if (prev < 0) continue;
            dp[j] = min(dp[j], pack[prev] + pack[i]);
        }
    }


    cout << dp[n] << '\n';
    return 0;
}