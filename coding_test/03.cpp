#include <iostream>
using namespace std;

int t;
int m, n, x, y;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main()
{
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> m >> n >> x >> y;
        
        int shutdown = lcm(m, n);
        int j;
        for (j = x; j <= shutdown; j += m) {
            int tmp = (j % n == 0) ? n : j % n;
            if (tmp == y) {
                cout << j << '\n';
                break;
            }
        }
        if (j > shutdown) cout << -1 << '\n';
    }
    return 0;
}