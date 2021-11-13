#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#define INF 200000000
using namespace std;

class Info {
public:
    int n;
    double cost;

    Info (int a, double b) {
        this->n = a;
        this->cost = b;
    }
    bool operator<(const Info s) const {
        return this->cost > s.cost;
    }
};

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
    double m;
    cin >> n >> w >> m;
    vector<vector<double> > map(n+1, vector<double> (n+1, INF));
    vector<double> dp(n+1, INF);
    vector<pair<int, int> > loc(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y;
        loc[i] = make_pair(x, y);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            x1 = loc[i].first; y1 = loc[i].second;
            x2 = loc[j].first; y2 = loc[j].second;
            double dist = distance(x1, y1, x2, y2);
            if (dist <= m) {
                map[i][j] = dist;
            }
        }
    }
    for (int i = 1; i <= w; ++i) {
        cin >> a >> b;
        map[a][b] = 0;
        map[b][a] = 0;
    }

    priority_queue<Info> pq;
    pq.push(Info(1, 0.0));
    dp[1] = 0;
    while(!pq.empty()) {
        Info f = pq.top();
        pq.pop();
        if (dp[f.n] < f.cost) continue;
        if (f.n == n) continue;
        for (int i = 1; i <= n; ++i) {
            if (map[f.n][i] == INF) continue;
            double nextCost = f.cost + map[f.n][i];
            if (dp[i] > nextCost) {
                dp[i] = nextCost;
                pq.push(Info(i, nextCost));
            }
        }
    }
    cout << round(1000 * dp[n]) << endl;
    return 0;
}