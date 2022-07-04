#include <iostream>
using namespace std;

int res;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    res = (c-b > b-a) ? c-b-1 : b-a-1;
    cout << res << '\n';
    return 0;
}