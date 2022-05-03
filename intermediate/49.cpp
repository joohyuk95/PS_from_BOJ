#include <iostream>
using namespace std;

string s[3];

int main()
{
    cin >> s[0] >> s[1] >> s[2];

    for (int i = 0; i < 3; ++i) {
        int cnt = 1;
        int max = 0;
        for (int j = 1; j < s[i].size(); ++j) {
            if (s[i][j-1] == s[i][j]) {
                cnt++;
                if (cnt > max) max = cnt;
            } else {
                cnt = 1;
            }
        }
        if (max) cout << max << '\n';
        else cout << 1 << '\n';
    }
    return 0;
}