#include <iostream>
using namespace std;

int t, sum;
bool alpha[26];

int main()
{
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        string str; cin >> str;

        for (int j = 0; j < str.size(); ++j) {
            alpha[int(str[j]) - 'A'] = true;
        }
        for (int j = 0; j < 26; ++j) {
            if (!alpha[j]) sum += 65 + j;
        }
        cout << sum << '\n';

        for (int j = 0; j < 26; ++j) alpha[j] = false;
        sum = 0;
    }

    return 0;
}