#include <iostream>
using namespace std;

int n;
int sum = 1;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a; cin >> a;
        
        sum += a - 1;
    }

    cout << sum << '\n';
    return 0;
}