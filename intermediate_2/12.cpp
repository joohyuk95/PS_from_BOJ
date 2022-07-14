#include <iostream>
using namespace std;

int t;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        int n; cin >> n;
        int max_val = n;
        while (n != 1) {
            if (n % 2) {
                n = n*3 + 1;
                if (n > max_val) max_val = n;
            }
            else n /= 2;
        }
        cout << max_val << '\n';
    }

    return 0;
}