#include <iostream>
#include <vector>
#include <cmath>
#define INF 150000
using namespace std;

double distance(int fx, int fy, int sx, int sy)
{
    if (fx == sx) return abs(fy-sy);
    else if (fy == sy) return abs(fx-sx);
    else return sqrt(pow(fx-sx, 2) + pow(fy-sy, 2));
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n, w, x, y, a, b, x1, x2, y1, y2;
    double m, dist;
    cin >> n >> w >> m;
    vector<vector<double> > map(n+1, vector<double> (n+1, INF));
    vector<int> cost(n+1, INF);
    vector<pair<int, int> > loc(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y;
        loc[i] = make_pair(x, y);
    }
    for (int i = 1; i <= w; ++i) {
        cin >> a >> b;
        map[a][b] = 0;
        map[b][a] = 0;
    }
    for (int i = 1; i <= n; ++i) map[i][i] = 0;
    for (int i = 1; i <= n-1; ++i) {
        for (int j = i+1; j <= n; ++j) {
            if (map[i][j] == 0) continue;
            x1 = loc[i].first; y1 = loc[i].second;
            x2 = loc[j].first; y2 = loc[j].second;
            dist = distance(x1, y1, x2, y2);
            if (dist <= m) {
                map[i][j] = dist;
                map[j][i] = dist;
            }
        }
    }

    for (int k = 1; k <= n; ++k) {
        for (int j = 1; j <= n; ++j) {
            map[1][j] = min(map[1][j], map[1][k] + map[k][j]);
        }
    }
    cout << round(1000 * map[1][n]) << endl;
    return 0;
}