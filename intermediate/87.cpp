#include <iostream>
using namespace std;

int n;
int sum;

int main()
{
    cin >> n;
    for (int i = 0; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            sum += i+j;
        }
    }
    cout << sum << '\n';
    return 0;
}