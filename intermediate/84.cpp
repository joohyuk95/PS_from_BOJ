#include <iostream>
using namespace std;

int n;

int main()
{
    cin >> n;

    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        ans *= 2;
    }
    ans++;
    ans *= ans;

    cout << ans << '\n';
    return 0;
}