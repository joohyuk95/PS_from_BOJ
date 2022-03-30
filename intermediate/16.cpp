#include <iostream>
using namespace std;

int n, cnt;
bool seat[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a; cin >> a;
        
        if (seat[a]) cnt++;
        else seat[a] = true;
    }

    cout << cnt << '\n';
    return 0;
}