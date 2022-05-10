#include <iostream>
#include <string>
using namespace std;

int digit[10];

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    
    int total = a * b * c;
    string str = to_string(total);

    for (int i = 0; i < str.size(); ++i) {
        digit[int(str[i])-48]++;
    }

    for (int i = 0; i < 10; ++i) {
        cout << digit[i] << '\n';
    }

    return 0;
}