#include <iostream>
#include <algorithm>
using namespace std;

int t, n;
pair<int, int> info[100000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> t;
    for (int k = 1; k <= t; ++k) {
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> info[i].first >> info[i].second;
        }
        sort(info, info + n);

        int top = n + 1;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (info[i].second < top) {
                top = info[i].second;
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}