#include <iostream>
using namespace std;

int n, sum;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a, b; cin >> a >> b;
        if (a > b) sum += b;
        else sum += b % a;
    }

    cout << sum << '\n';
    return 0;
}