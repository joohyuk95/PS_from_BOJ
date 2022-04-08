#include <iostream>
using namespace std;

int a, b, c;
long long res;

int main()
{
    cin >> a >> b >> c;
    if (b >= c) {
        cout << -1 << '\n';
        exit(0);
    } else {
        res = a / (c-b) + 1;
        cout << res << '\n';
    }
    return 0;
}