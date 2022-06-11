#include <iostream>
using namespace std;

string multiple(int n, bool flag)
{
    string s;
    if (flag) s = "1";
    else s = "2";

    for (int i = 1; i <= n; ++i) {
        s += "0";
    }
    return s;
}

string adding(int a, int b)
{
    string res;
    if (a == b) {
        res = "2";
        for (int i = 1; i < a; ++i) res += "0";
    } else {
        res = "1";
        if (a > b) {
            for (int i = 1; i < a-b; ++i) res += "0";
            res += "1";
            for (int i = 1; i < b; ++i) res += "0";
        } else {
            for (int i = 1; i < b-a; ++i) res += "0";
            res += "1";
            for (int i = 1; i < a; ++i) res += "0";
        }
    }
    return res;
}

int main()
{
    string a, b;
    char op;
    cin >> a >> op >> b;

    if (op == '*') {
        cout << multiple(a.size()+b.size()-2, 1) << '\n';
    } else {
        cout << adding(a.size(), b.size()) << '\n';
    }
    return 0;
}