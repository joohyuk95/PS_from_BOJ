#include <iostream>
using namespace std;

int n, cnt;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        if (1 <= i && i < 100) {
            cnt++;
        } else if (100 <= i && i < 1000) {
            int a = i / 100;
            int b = (i % 100) / 10;
            int c = i % 10;
            if (a + c == 2 * b) cnt++;
        }
    }

    cout << cnt << '\n';
    return 0;
}