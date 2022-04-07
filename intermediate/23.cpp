#include <iostream>
using namespace std;

int n, res;
int dp[501];

int main()
{
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        int tmp = i;
        while (1) {
            if (tmp % 5 == 0) {
                cnt++;
                tmp /= 5;
            } else {
                break;
            }
        }
        dp[i] = cnt;
    }

    for (int i = 1; i <= n; ++i) {
        res += dp[i];
    }
    cout << res << '\n';
    return 0;
}