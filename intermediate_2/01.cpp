#include <iostream>
using namespace std;

int cnt;

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    for (int i = 0; i < str1.size(); ++i) {
        if (str1[i] == 0) break;
        for (int j = 0; j < str2.size(); ++j) {
            if (str2[j] == 0) break;
            if (str1[i] == str2[j]) {
                str1[i] = '0';
                str2[j] = '0';
            }
        }
    }

    for (int i = 0; i < str1.size(); ++i) if (str1[i] != '0') cnt++;
    for (int i = 0; i < str2.size(); ++i) if (str2[i] != '0') cnt++;

    cout << cnt << '\n';
    return 0;
}