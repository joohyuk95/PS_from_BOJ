#include <iostream>
#include <algorithm>
using namespace std;

int n, len, cnt;
int loc[1000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> len;
    for (int i = 0; i < n; ++i) {
        cin >> loc[i];
    }
    sort(loc, loc + n);

    int start = loc[0];
    for (int i = 1; i < n; ++i) {
        if (loc[i] - start >= len) {
            cnt++;
            start = loc[i];
        }
    }
    cout << cnt + 1 << '\n';
    return 0;
}