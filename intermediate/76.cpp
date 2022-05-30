#include <iostream>
using namespace std;

int main()
{
    int l, p;
    cin >> l >> p;
    for (int i = 1; i <= 5; ++i) {
        int num; cin >> num;
        cout << num - l*p << ' ';
    }
    cout << '\n';
    return 0;
}