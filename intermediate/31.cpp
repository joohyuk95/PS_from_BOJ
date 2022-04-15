#include <iostream>
using namespace std;

int m, n, sum;

int main()
{
    cin >> m >> n;

    int i = 1;
    int min = 0;
    bool flag = true;

    while (true) {
        if (m <= i*i && i*i <= n) {
            if (flag) {
                flag = false;
                min = i*i;
            }
            sum += i*i;
        }
        if (i*i > n) break;
        ++i;
    }

    if (min == 0) cout << -1 << '\n';
    else cout << sum << '\n' << min << '\n';
    return 0;
}