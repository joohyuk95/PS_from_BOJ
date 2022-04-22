#include <iostream>
using namespace std;

int n;
int sum, cnt;

int main()
{
    cin >> n;

    sum = 1;
    while (true) {
        if (n <= sum) break;

        cnt++;
        sum += cnt*6;
    }

    cout << cnt + 1 << '\n';
    return 0;
}