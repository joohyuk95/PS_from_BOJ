#include <iostream>
#include <vector>
#define INF 4000000
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int v, e, a, b, c, minimum = 4000000;
    cin >> v >> e;
    vector<vector<int> > map(v+1, vector<int> (v+1, INF));
    for (int i = 1; i <= e; ++i) {
        cin >> a >> b >> c;
        map[a][b] = c;
    }
    for (int i = 1; i <= v; ++i) map[i][i] = 0;
    for (int k = 1; k <= v; ++k) {
        for (int i = 1; i <= v; ++i) {
            for (int j = 1; j <= v; ++j) {
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }

    for (int i = 1; i <= v; ++i) {
        for (int j = 1; j <= v; ++j) {
            if (i == j) continue;
            if (map[i][j] + map[j][i] < minimum) minimum = map[i][j] + map[j][i];
        }
    }
    if (minimum == 4000000) cout << -1 << endl;
    else cout << minimum << endl;
    return 0;
}