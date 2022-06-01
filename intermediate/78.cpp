#include <iostream>
using namespace std;

int sum, pre, cur, ans;
bool flag;

int main()
{
    for (int i = 1; i <= 10; ++i) {
        cin >> cur;
        if (flag) continue;
        
        sum += cur;
        if (sum >= 100) {
            if (sum-100 > 100-(sum-cur)) ans = sum - cur;
            else ans = sum;
            flag = true;
        } else {
            pre = cur;
        }
    }
    if (flag) cout << ans << '\n';
    else cout << sum << '\n';
    return 0;
}