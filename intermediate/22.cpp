#include <iostream>
using namespace std;

int num1, num2;

int main()
{
    cin >> num1 >> num2;

    int height1 = num1 % 4 ? num1 % 4 : 4;
    int width1 = num1 % 4 ? num1 / 4 + 1 : num1 / 4;

    int height2 = num2 % 4 ? num2 % 4 : 4;
    int width2 = num2 % 4 ? num2 / 4 + 1 : num2 / 4;

    cout << abs(height1 - height2) + abs(width1 - width2) << '\n';
    return 0;
}