#include <iostream>
using namespace std;

int n;
string str;

void is_nice(string s)
{
    int alpha = 26*26*(int(s[0])-65) + 26*(int(s[1])-65) + int(s[2])-65;
    int digit = 1000*(int(s[4])-48) + 100*(int(s[5])-48) + 10*(int(s[6])-48) + int(s[7])-48;

    if (abs(alpha - digit) <= 100) cout << "nice" << '\n';
    else cout << "not nice" << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> str;
        is_nice(str);
    }

    return 0;
}