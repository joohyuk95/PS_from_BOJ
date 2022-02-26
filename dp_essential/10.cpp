#include <iostream>
using namespace std;

int n, ans;
int arr[1001];
int dp[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        dp[i] = 1;
    }

    for (int i = 2; i <= n; ++i) {
        int max = 0;
        for (int j = 1; j < i; ++j) {
            if (arr[j] < arr[i]) {
                if (dp[j] > max) max = dp[j];
            }
        }
        dp[i] = max + 1;
    }

    for (int i = 1; i <= n; ++i) {
        if (dp[i] > ans) ans = dp[i];
    }
    cout << ans << '\n';
    return 0;
}