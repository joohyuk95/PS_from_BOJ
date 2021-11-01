#include <iostream>
#include <vector>
#define INF 200000
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m, a, b, c;
    cin >> n >> m;
    vector<vector<int> > map(n+1, vector<int> (n+1, INF));
    vector<vector<int> > copy(n+1, vector<int> (n+1));
    for (int i = 1; i <= m; ++i) {
        cin >> a >> b >> c;
        map[a][b] = c;
        map[b][a] = c;
        copy[a][b] = c;
        copy[b][a] = c;
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
            if (i == j) cout << "- ";
            else if (map[i][j] == copy[i][j]) cout << j << ' ';
            else {
                for (int k = 1; k <= n; ++k) {
                    if (i == k) continue;
                    if (map[i][k] != INF && (map[i][j] == copy[i][k] + map[k][j])) {
                        cout << k << ' ';
                        break;
                    }
                }
            }
        }
        cout << endl;
    }
    return 0;
}