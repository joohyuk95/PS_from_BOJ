#include <iostream>
#include <string>
using namespace std;

int n, cnt;

int alpha[26];
string str;

bool is_group(string s)
{
    string new_s; new_s += s[0];
    for (int i = 0; i < 26; ++i) alpha[i] = 0;

    int length = s.length();
    if (length > 1) {
        for (int i = 1; i < length; ++i) {
            char temp = s[i - 1];
            if (s[i] != temp) new_s += s[i];
        }
    }

    int len = new_s.length();
    int word_cnt = 0;
    for (int i = 0; i < len; ++i) {
        alpha[new_s[i] - 97]++;
    }
    for (int i = 0; i < 26; ++i) {
        if (alpha[i]) word_cnt++;
    }

    if (len == word_cnt) return true;
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> str;
        if (is_group(str)) cnt++;
    }

    cout << cnt << '\n';
    return 0;
}