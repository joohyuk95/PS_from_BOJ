#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 10000000
using namespace std;
vector<pair<int, int> > map[1000];

class Info {
public:
    int node, cost;

    bool operator<(const Info &rhs) const {
        return this->cost > rhs.cost;
    }
};
priority_queue<Info> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> dist(n, INF);
    for (int i = 1; i <= m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        map[a].push_back(make_pair(b, c));
        map[b].push_back(make_pair(a, c));
    }
    
    dist[y] = 0;
    pq.push({y, 0});
    while (!pq.empty()) {
        int node = pq.top().node;
        int cost = pq.top().cost;
        pq.pop();
        if (dist[node] < cost) continue;

        for (int i = 0; i < map[node].size(); ++i) {
            int nextNode = map[node][i].first;
            int nextCost = map[node][i].second;
            if (dist[nextNode] > dist[node] + nextCost) {
                dist[nextNode] = dist[node] + nextCost;
                pq.push({nextNode, dist[nextNode]});
            }
        }
    }
    sort(dist.begin(), dist.end());
    for (int i = 0; i < n; ++i) {
        dist[i] *= 2;
        if (dist[i] > x) {
            cout << -1 << endl;
            exit(0);
        }
    }

    int cnt = 1;
    int hp = x;
    for (int i = 0; i < n; ++i) {
        hp -= dist[i];
        if (hp < 0) {
            hp = x - dist[i];
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}