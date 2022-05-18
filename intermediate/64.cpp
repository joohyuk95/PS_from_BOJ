#include <iostream>
using namespace std;

int t;

void print_gcd_lcm(int a, int b)
{
    int r;
    int multiple = a * b;
    if (b > a) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    while (b) {
        r = a % b;
        a = b;
        b = r;
    }

    int gcd = a;
    cout << multiple / gcd << ' ' << gcd << '\n';
}

int main()
{
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        int a, b;
        cin >> a >> b;
        print_gcd_lcm(a, b);
    }
    return 0;
}