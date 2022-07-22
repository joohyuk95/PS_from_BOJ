#include <iostream>
using namespace std;

int main()
{
    while (true) {
        int a, b, c;
        cin >> a >> b >> c;
        if (!a && !b && !c) break;

        if (2*b == a+c) {
            cout << "AP " << c + (c-b) << '\n';
        } else {
            cout << "GP " << c/b * c << '\n';
        }
    }

    return 0;
}