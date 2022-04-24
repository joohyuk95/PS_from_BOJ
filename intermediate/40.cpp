#include <iostream>
using namespace std;

int t;
int prime[100001];

void primeFactor(int n)
{
    int num = n;
    for (int i = 2; i <= n; ++i) prime[i] = 0;
    for (int i = 2; i*i <= n; ++i) {
        while (num % i == 0) {
            prime[i]++;
            num /= i;
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (prime[i]) {
            cout << i << ' ' << prime[i] << '\n';
        }
    }
    if (num > 1) cout << num << ' ' << 1 << '\n';
}

int main()
{
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int a; cin >> a;
        primeFactor(a);
    }

    return 0;
}