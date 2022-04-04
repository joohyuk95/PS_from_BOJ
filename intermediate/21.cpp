#include <iostream>
using namespace std;

int main()
{
    int pos = 1;
    int m;
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        int a, b; cin >> a >> b;
        if (a == pos) pos = b;
        else if (b == pos) pos = a;
    }

    cout << pos << '\n';
    return 0;
}