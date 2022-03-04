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

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i] = max(dp[i], dp[i - j] + pack[j]);
        }
    }


    cout << dp[n] << '\n';
    return 0;
}