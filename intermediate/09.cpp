#include <iostream>
#include <string>
using namespace std;

long long res;
string a, b;

int main()
{
    cin >> a;
    if (a == "0");
    else cin >> b;
    int asize = a.size();
    int bsize = b.size();

    for (int i = 0; i < asize; ++i) {
        for (int j = 0; j < bsize; ++j) {
            int x = a[i] - 48;
            int y = b[j] - 48;
            res += x * y;
        }
    }

    cout << res << '\n';
    return 0;
}