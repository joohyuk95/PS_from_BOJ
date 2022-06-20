#include <iostream>
#include <string>
using namespace std;

string n;
int m;

int nums[10];
bool check[10];

int malfunc(int n)
{
    if (n == 0) {
        if (check[0]) {
            return 0;
        } else {
            return 1;
        }
    }
    int len = 0;
    while (n > 0) {
        if (check[n % 10]) return 0;
        n = n / 10;
        len += 1;
    }

    return len;
}

int main()
{
    cin >> n >> m;
    if (m > 0) {
        for (int i = 1; i <= m; ++i) {
            int a; cin >> a;
            check[a] = true;
        }
    } else {
        cout << n.size() << '\n';
        return 0;
    }

    int res = abs(stoi(n)-100);
    for (int i = 0; i <= 1000000; ++i) {
        int digit = i;
        int len = malfunc(digit);
        if (len > 0) {
            int press = abs(digit - stoi(n));
            if (res > press + len) {
                res = press + len;
            }
        }
    }

    cout << res << '\n';
    return 0;
}