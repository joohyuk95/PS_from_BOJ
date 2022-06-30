#include <iostream>
using namespace std;

int n, s, cnt;
int seq[21];

void check(int cur, int sum)
{
    if (cur == n + 1) {
        if (sum == s) cnt++;
        return;
    }

    check(cur + 1, sum);
    check(cur + 1, sum + seq[cur]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> s;
    for (int i = 1; i <= n; ++i) {
        cin >> seq[i];
    }

    check(1, 0);

    if (s == 0) cnt--;
    cout << cnt << '\n';

    return 0;
}