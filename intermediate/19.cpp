#include <iostream>
using namespace std;

bool fourseven(int n)
{
    while (n) {
        if (n % 10 == 4 || n % 10 == 7) {
            n /= 10;
        } else {
            return false;
        }
    }
    return true;
}

int main()
{
    int n, ans;
    cin >> n;

    for (int i = n; i >= 4; --i) {
        if (fourseven(i)) {
            ans = i;
            break;
        }
    }

    cout << ans << '\n';
    return 0;
}