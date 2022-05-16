#include <iostream>
using namespace std;

int t;

int main()
{
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int r;
        string s;
        cin >> r >> s;

        string new_s = "";
        for (int j = 0; j < s.size(); ++j) {
            for (int k = 1; k <= r; ++k) {
                new_s += s[j];
            }
        }
        cout << new_s << '\n';
    }
    return 0;
}