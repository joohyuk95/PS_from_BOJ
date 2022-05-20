#include <iostream>
using namespace std;

int t;

int main()
{
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int num; cin >> num;
        string s; cin >> s;
        
        for (int j = 0; j < num-1; ++j) cout << s[j];
        for (int j = num; j < s.size(); ++j) cout << s[j];
        cout << '\n';
    }

    return 0;
}