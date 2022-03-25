#include <iostream>
using namespace std;

int a, b;
int arr[1001];

int main()
{
    cin >> a >> b;

    int num = 1;
    int index = 1;
    while (index <= 1000) {
        for (int j = 1; j <= num; ++j) {
            arr[index++] = num;
            if (index > 1000) break;
        }
        num++;
    }

    int res = 0;
    for (int i = a; i <= b; ++i) {
        res += arr[i];
    }
    cout << res << '\n';
    return 0;
}