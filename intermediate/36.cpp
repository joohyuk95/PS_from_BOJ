#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int res = (n - 1) + n*(m-1);
    cout << res << '\n';
    return 0;
}