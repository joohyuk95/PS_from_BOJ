#include <iostream>
using namespace std;

string bi2oct(string str)
{
    if (str == "000") return "0";
    else if (str == "001") return "1";
    else if (str == "010") return "2";
    else if (str == "011") return "3";
    else if (str == "100") return "4";
    else if (str == "101") return "5";
    else if (str == "110") return "6";
    else return "7";
}

int main()
{
    string str;
    cin >> str;

    switch (str.size() % 3) {
        case 1:
            str = "00"+str;
            break;
        case 2:
            str = "0"+str;
            break;
        default:
            break;
    }

    int cnt = str.size() / 3;
    string new_str = "";
    for (int i = 0; i < cnt; ++i) {
        new_str += bi2oct(str.substr(i*3,3));
    }
    cout << new_str << '\n';
    return 0;
}