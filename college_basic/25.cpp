#include <iostream>
using namespace std;

int n, newScore, p;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> newScore >> p;
    int cnt = 1;
    int a;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        if (a > newScore) cnt++;
    }

    if (n == p && a >= newScore) cnt = -1;
    cout << cnt << endl;
    
    return 0;
}