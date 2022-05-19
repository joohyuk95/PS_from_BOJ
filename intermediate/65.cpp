#include <iostream>
using namespace std;

int t;

int main()
{
    cin >> t;
    cin.ignore();
    for (int i = 1; i <= t; ++i) {
        string s, rule;
        getline(cin, s);
        getline(cin, rule);

        for (int j = 0; j < s.size(); ++j) {
            if (s[j] != ' ') s[j] = rule[int(s[j])-65];
        }

        cout << s << '\n';
    }

    return 0;
}