#include <iostream>
using namespace std;

int e, s, m, cnt;

int main()
{
    cin >> e >> s >> m;

    int a = 1; int a_mod = 15;
    int b = 1; int b_mod = 28;
    int c = 1; int c_mod = 19;

    while (true) {
        cnt++;
        a = a % a_mod;
        b = b % b_mod;
        c = c % c_mod;

        if (a == 0) a = a_mod;
        if (b == 0) b = b_mod;
        if (c == 0) c = c_mod;

        if (a == e && b == s && c == m) break;
        a++;
        b++;
        c++;
    }

    cout << cnt << '\n';
    return 0;
}