#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int> > map(n+1, vector<int> (n+1, 100));
    for (int i = 1; i <= m; ++i) {
        cin >> a >> b;
        map[a][b] = 1;
    }
    for (int i = 1; i <= n; ++i) map[i][i] = 0;
    for (int k = 1; k <= n; ++k) {
        for (int j = 1; j <= n; ++j) {
            for (int i = 1; i <= n; ++i) {
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }    
    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        for (int j = 1; j <= n; ++j) {
            if (map[i][j] == 100) cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}