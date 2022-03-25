#include <iostream>
using namespace std;

int a, b, sum, res;

int summ[1001];
int arr[1001];

int main()
{
    cin >> a >> b;

    int num = 1;
    while (1) {
        summ[num] = summ[num - 1] + num;
        if (summ[num] > 1000) break;
        ++num;
    }

    int cnt = 1;
    for (int i = 1; i <= 1000; ++i) {
        arr[i] = cnt;
        if (summ[cnt] == i) cnt++;
    }

    for (int i = a; i <= b; ++i) {
        res += arr[i];
    }
    cout << res << '\n';
    return 0;
}