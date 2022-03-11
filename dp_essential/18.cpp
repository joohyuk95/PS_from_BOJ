#include <iostream>
using namespace std;

int n;
int score[301];
int dp[301];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> score[i];

    dp[1] = score[1];
    dp[2] = score[1] + score[2];
    dp[3] = max(score[1], score[2]) + score[3];

    for (int i = 3; i <= n; ++i) {
        dp[i] = max(dp[i - 2], dp[i - 3] + score[i - 1]) + score[i];
    } 

    cout << dp[n] << '\n';
    return 0;
}