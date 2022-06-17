#include <iostream>
using namespace std;

int a, b, c, d;
int p, m, n;
int arrival;

int main()
{
    cin >> a >> b >> c >> d;

    for (int i = 1; i <= 3; ++i) {
        int ans = 0;
        cin >> arrival;
        int check1 = arrival % (a+b);
        int check2 = arrival % (c+d);

        if (0 < check1 && check1 <= a) ans++;
        if (0 < check2 && check2 <= c) ans++;
        cout << ans << '\n';
    }

    return 0;
}