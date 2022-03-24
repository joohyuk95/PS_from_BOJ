#include <iostream>
using namespace std;

int a, b, c, maxi;
int sum[81];

int main()
{
    cin >> a >> b >> c;

    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= b; ++j) {
            for (int k = 1; k <= c; ++k) {
                sum[i + j + k]++;
            }
        }
    }

    for (int i = 3; i <= a + b + c; ++i) {
        if (sum[i] > maxi) maxi = sum[i];
    }

    for (int i = 3; i <= a + b + c; ++i) {
        if (sum[i] == maxi) {
            cout << i << '\n';
            break;
        }
    }
    return 0;
}