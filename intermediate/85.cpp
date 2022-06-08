#include <iostream>
using namespace std;

string num1, num2;
bool flag;

int main()
{
    cin >> num1 >> num2;
    
    for (int i = 2; i >= 0; --i) {
        int a = int(num1[i])-48;
        int b = int(num2[i])-48;

        if (a == b) continue;
        if (a > b) flag = true;
        break;
    }

    for (int i = 2; i >= 0; --i) {
        if (flag) cout << num1[i];
        else cout << num2[i];
    }
    cout << '\n';
    return 0;
}