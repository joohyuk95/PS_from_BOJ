#include <iostream>
using namespace std;

int t;

int T(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        sum += i;
    }
    return sum;
}

int W(int n)
{
    int sum = 0;
    for (int k = 1; k <= n; ++k) {
        sum += k*T(k+1);
    }
    return sum;
}

int main()
{
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int n; cin >> n;
        cout << W(n) << '\n';
    }
    return 0;
}