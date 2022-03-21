#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
bool flag;
string str;
char arpha[26];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> str;
        int index = str[0] - 97;
        arpha[index]++;
    }

    for (int i = 0; i < 26; ++i) {
        if (arpha[i] >= 5) {
            cout << (char)(i + 97);
            flag = true;
        }
    }

    if (!flag) {
        cout << "PREDAJA" << '\n';
    }

    return 0;
}