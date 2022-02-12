#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int t, n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> t;
    for (int k = 1; k <= t; ++k) {
        cin >> n;
        vector<string> str;
        for (int i = 0; i < n; ++i) {
            string s; cin >> s;
            str.push_back(s);
        }
        sort(str.begin(), str.end());

        bool flag = true;
        for (int i = 0; i < str.size() - 1; ++i) {
            string cur = str[i];
            string next = str[i + 1];
            if (cur.length() > next.length()) continue;
            if (cur == next.substr(0, cur.length())) {
                flag = false;
                break;
            }
        }
        if (!flag) cout << "NO" << '\n';
        else cout << "YES" << '\n';
    }

    return 0;
}