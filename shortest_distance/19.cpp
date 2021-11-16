#include <iostream>
#include <vector>
using namespace std;
int dist[10001];
vector<pair<int, int> > Info[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    int n, d, s, e, c, prev;
    cin >> n >> d;
    for (int i = 1; i <= d; ++i) dist[i] = i;
    for (int i = 1; i <= n; ++i) {
        cin >> s >> e >> c;
        if (e - s <= c) continue;
        if (e > d) continue;
        Info[s].push_back(make_pair(e, c));
    }
    for (int i = 0; i <= d; ++i) {
        if (i == 0) prev = -1;
        else prev = dist[i-1];
        dist[i] = min(dist[i], prev + 1);
        if (!Info[i].empty()) {
            for (int j = 0; j < Info[i].size(); ++j) {
                int next = Info[i][j].first;
                int cost = Info[i][j].second;
                if (dist[next] > dist[i] + cost) dist[next] = dist[i] + cost;
            }
        }
    }
    cout << dist[d] << endl;
    return 0;
}