#include <iostream>
#include <vector>
#define INF 10000000
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m, a, b, c;
    cin >> n >> m;
    vector<vector<int> > map(n+1, vector<int> (n+1, INF));
    for (int i = 1; i <= m; ++i) {
        cin >> a >> b >> c;
        if (map[a][b] > c) map[a][b] = c;
    }
    for (int i = 1; i <= n; ++i) map[i][i] = 0;
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (map[i][j] == INF) cout << "0 ";
            else cout << map[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}