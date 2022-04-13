#include <iostream>
using namespace std;

int n;
long long sum;

int main()
{
    cin >> n;
    sum = 5;
    for (int i = 2; i <= n; ++i) {
        sum += 4 + 3*(i-1);
    }

    cout << sum % 45678 << '\n';
    return 0;
}