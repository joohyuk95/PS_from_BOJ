#include <iostream>
#include <string>
using namespace std;

string dividenum(int num)
{
    string str = to_string(num);
    if (str.size() == 1) return str;

    int sum = 0;
    for (int i = 0; i < str.size(); ++i) {
        sum += int(str[i]) - 48;
    }

    if (sum / 10) return dividenum(sum);
    else return to_string(sum);
}

int main()
{
    ios_base::sync_with_stdio(false);

    int a;
    while (true) {
        cin >> a;
        if (a == 0) break;
        cout << dividenum(a) << '\n';
    }

    return 0;
}