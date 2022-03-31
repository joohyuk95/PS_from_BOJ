#include <iostream>
#include <string>
using namespace std;

string s;
int digit[10];

int main()
{
    cin >> s;

    int len = s.length();
    for (int i = 0; i < len; ++i) {
        int tmp = s[i] - 48;
        if (tmp == 9) digit[6]++;
        else digit[tmp]++;
    }

    if (digit[6] % 2) {
        digit[6] = (digit[6] / 2) + 1;
    } else {
        digit[6] = digit[6] / 2;
    }

    int max = 0;
    for (int i = 0; i < 9; ++i) {
        if (digit[i] > max) {
            max = digit[i];
        }
    }

    cout << max << '\n';
    return 0;
}