#include <iostream>
#include <string>
using namespace std;

char max_index;
int maxi, cnt;
int alpha[26];

int main()
{
    ios_base::sync_with_stdio(false);
    
    string str;
    cin >> str;
    int size = str.length();

    for (int i = 0; i < size; ++i) {
        char ch; ch = str[i];
        if ('A' <= ch && ch <= 'Z') {
            alpha[ch - 'A']++;
        } else {
            alpha[ch - 'a']++;
        }
    }
    
    for (int i = 0; i < 26; ++i) {
        if (alpha[i] > maxi) maxi = alpha[i];
    }
    for (int i = 0; i < 26; ++i) {
        if (alpha[i] == maxi) {
            cnt++;
            max_index = i;
        }
    }
    
    char res = max_index + 'A';
    if (cnt > 1) {
        cout << '?' << '\n';
    } else {
        cout << res << '\n';
    }
    return 0;
}