#include <iostream>
using namespace std;

int t;

int main()
{
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int n; cin >> n;
        
        int cnt = 0;
        while (n) {
            if (n % 2 == 1) cout << cnt << ' ';

            n = n / 2;
            cnt++;
        }
    }
    return 0;
}