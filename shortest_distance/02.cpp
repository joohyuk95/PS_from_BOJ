#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, a;
    cin >> n;
    vector<vector<int> > map(n+1, vector<int> (n+1, 1000));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a;
            if (a == 1) map[i][j] = a;
        }
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (map[i][j] == 1000) cout << 0 << ' ';
            else cout << 1 << ' ';
        }
        cout << endl;
    }
    return 0;
}