#include <iostream>
#include <string>
using namespace std;

string str;
string new_s;

int main()
{
    cin >> str;

    for  (int i = 0; i < str.size(); ++i) {
        if ('A' <= str[i] && str[i] <= 'Z') new_s += str[i];
    }

    cout << new_s << '\n';
    return 0;
}