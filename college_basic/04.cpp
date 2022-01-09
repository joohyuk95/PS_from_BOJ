#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int tmp = n;
    int cnt = 0;
    while (true) {
        if (tmp < 10) {
            tmp = tmp * 10 + tmp;
        } else {
            int a = tmp / 10;
            int b = tmp % 10;
            int c = (a + b) % 10;
            tmp = b * 10 + c;
        }
        cnt++;
        if (tmp == n) break;
    }
    cout << cnt << endl;
    return 0;
}