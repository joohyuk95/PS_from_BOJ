#include <iostream>
using namespace std;

int m, n, first, sum;
bool is_prime[10001];

int main()
{
    cin >> m >> n;
    for (int i = 2; i <= n; ++i) is_prime[i] = true;

    for (int i = 2; i*i <= n; ++i) {
        if (is_prime[i]) {
            for (int j = i*i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (int i = m; i <= n; ++i) {
        if (is_prime[i]) {
            if (!first) first = i;
            sum += i;
        }
    }

    if (first) {
        cout << sum << '\n' << first << '\n';
    } else  {
        cout << -1 << '\n';
    }
    return 0;
}