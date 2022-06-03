#include <iostream>
using namespace std;

int toFive(string s)
{
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '6') s[i] = '5';
    }
    return stoi(s);
}

int toSix(string s)
{
for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '5') s[i] = '6';
    }
    return stoi(s);
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    int ans1 = toFive(str1) + toFive(str2);
    int ans2 = toSix(str1) + toSix(str2);

    cout << ans1 << ' ' << ans2 << '\n';
    return 0;
}