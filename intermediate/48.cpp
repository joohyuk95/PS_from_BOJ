#include <iostream>
using namespace std;

int n;

int main()
{
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i-1; ++j) cout << ' ';
        for (int j = 1; j <= 2*(n+1-i)-1; ++j) cout << '*';
        cout << '\n';
    }
    for (int i = 1; i <= n-1; ++i) {
        for (int j = 1; j <= n-1-i; ++j) cout << ' ';
        for (int j = 1; j <= 2*(i+1)-1; ++j) cout << '*';
        cout << '\n';
    }
    return 0;
}
