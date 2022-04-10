#include <iostream>
#include <string>
using namespace std;

int cnt;

int main()
{
    string str;
    cin >> str;
    while (str.size() != 1) {
        int sum = 0;
        for (int i = 0; i < str.size(); ++i) {
            sum += int(str[i]) - 48;
        }
        str = to_string(sum);
        cnt++;
    }
    cout << cnt << '\n';
    if (str == "3" || str == "6" || str == "9")
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
    return 0;
}