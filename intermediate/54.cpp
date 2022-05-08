#include <iostream>
using namespace std;

int hour, minuite;
int cooking;

int main()
{
    cin >> hour >> minuite >> cooking;

    int a = minuite + cooking;
    int b = a / 60;
    int c = a % 60;

    int d = (hour+b) % 24;

    cout << d << ' ' << c << '\n';
    return 0;
}