#include <iostream>
using namespace std;

int n, cnt;

int main()
{
    cin >> n;
    if (n < 10) {
        cout << n << '\n';
        return 0;
    }

    for (int i = 1; i <= n; i *= 10) {
        cnt += n - i  + 1;
    }
    cout << cnt << '\n';

    return 0;
}