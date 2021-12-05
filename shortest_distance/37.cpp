#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int> > map(n+1, vector<int> (n+1));
    for (int i = 1; i <= m; ++i) {
        int a, b; cin >> a >> b;
        map[a][b] = 1;
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (map[i][k] && map[k][j]) map[i][j] = 1;
            }
        }
    }

    int cnt = n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i == j) continue;
            if (!map[i][j] && !map[j][i]) {
                cnt--;
                break;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}