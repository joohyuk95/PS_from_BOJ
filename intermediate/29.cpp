#include <iostream>
using namespace std;

int t;
void print_lcm(int b, int a)
{
    int r;
    int multiple = a * b;
    while (b) {
        r = a % b;
        a = b;
        b = r;
    }

    int gcd = a;
    cout << multiple / gcd << '\n';
}

int main()
{
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int a, b;
        cin >> a >> b;
        print_lcm(a, b);
    }

    return 0;
}