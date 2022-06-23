#include <iostream>
using namespace std;

int n;
int table[16][16];
int dp[16]; // n번째 날부터 i번째 날까지 일했을 때 얻는 최대 이익

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> table[i][0] >> table [i][1];
    }
    
    for (int i = n; i >= 1; --i) {
        int prev = i + table[i][0];
        if (prev - 1 > n) dp[i] = dp[i + 1];
        else dp[i] = max(dp[i + 1], dp[prev] + table[i][1]);
    }

    cout << dp[1] << '\n';
    return 0;
}