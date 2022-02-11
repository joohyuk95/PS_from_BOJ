#include <iostream>
#include <string>
using namespace std;

int n;
string s;
bool flag;

void niceseq(string str, int length)
{
    if (flag) return;
    
    int len = str.size();
    for (int i = 1; i <= (len / 2); ++i) {
        if (str.substr(len - i, i) == str.substr(len - (2 * i), i)) return;
    }

    if (length > n) return;

    if (length == n) {
        flag = true;
        cout << str << '\n';
        return;
    } else {
        niceseq(str + '1', length + 1);
        niceseq(str + '2', length + 1);
        niceseq(str + '3', length + 1);
    }
}

int main()
{
    cin >> n;
    niceseq(s, 0);

    return 0;
}