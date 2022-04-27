#include <iostream>
using namespace std;

int n;

int main()
{
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i-1; ++j) {
            cout << ' ';
        }
        for (int k = 1; k <= n-i+1; ++k) {
            cout << '*';
        }
        cout << '\n';
    }

    return 0;
}