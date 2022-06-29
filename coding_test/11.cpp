#include <iostream>
using namespace std;

int m;
int bit;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m;
    for (int i = 1; i <= m; ++i) {
        string s;  int n;
        cin >> s;
        if (s == "add") {
            cin >> n;
            bit |= (1 << n);
        } else if (s == "remove") {
            cin >> n;
            bit &= ~(1 << n);
        } else if (s == "check") {
            cin >> n;
            if (bit & (1 << n)) cout << 1 << '\n';
            else cout << 0 << '\n';
        } else if (s == "toggle") {
            cin >> n;
            bit ^= (1 << n);
        } else if (s == "all")  {
            bit = (1 << 21) - 1;
        } else {
            bit = 0;
        }
    }

    return 0;
}