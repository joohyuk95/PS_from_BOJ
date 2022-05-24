#include <iostream>
using namespace std;

int char2int(char c)
{
    if (c >= 'A') return int(c)-55;
    else return int(c)-48;
}

int main()
{
    string str;
    int b;
    cin >> str >> b;

    int multiple = 1;
    for (int i = 1; i < str.size(); ++i) multiple *= b;

    int sum = 0;
    for (int i = 0; i < str.size(); ++i) {
        sum += char2int(str[i])*multiple;
        multiple /= b;
    }

    cout << sum << '\n';
    return 0;
}