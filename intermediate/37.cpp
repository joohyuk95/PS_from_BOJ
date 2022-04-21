#include <iostream>
using namespace std;

int n;

int main()
{
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
        int sum = i;
        int num = i;

        while (num) {
            sum += num % 10;
            num /= 10;
        }

        if (n == sum) {
            cout << i << '\n';
            return 0;
        }
    }

    cout << 0 << '\n';
    return 0;
}