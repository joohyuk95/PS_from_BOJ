#include <iostream>
#include <vector>
#define INF 200000
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int v, e, k, a, b, c;
    cin >> v >> e >> k;
    vector<vector<int> > map(v+1, vector<int> (v+1, INF));
    for (int i = 1; i <= e; ++i) {
        cin >> a >> b >> c;
        if (map[a][b] > c) map[a][b] = c;
    }
    for (int i = 1; i <= v; ++i) map[i][i] = 0;
    for (int p = 1; p <= v; ++p) {
        for (int i = 1; i <= v; ++i) {
            for (int j = 1; j <= v; ++j) {
                map[i][j] = min(map[i][j], map[i][p] + map[p][j]);
            }
        }
    }
    for (int i = 1; i <= v; ++i) {
        if (map[k][i] == INF) cout << "INF" << endl;
        else cout << map[k][i] << endl;
    }
    return 0;
}