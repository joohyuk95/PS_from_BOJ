#include <iostream>
#include <vector>
#include <queue>
#define INF 100000000
using namespace std;

vector<pair<int, int> > map[10001];
vector<int> dist_m(10001, INF);
vector<int> dist_s(10001, INF);

class Info {
public:
    int node, cost;

    bool operator<(const Info &rhs) const {
        return this->cost > rhs.cost;
    }
};
priority_queue<Info> pq;

void Dijkstra(vector<int> &dist)
{
    while (!pq.empty()) {
        int node = pq.top().node;
        int cost = pq.top().cost;
        pq.pop();
        
        for (int i = 0; i < map[node].size(); ++i) {
            int nextNode = map[node][i].first;
            int nextCost = map[node][i].second;
            if (dist[nextNode] > dist[node] + nextCost) {
                dist[nextNode] = dist[node] + nextCost;
                pq.push({nextNode, dist[nextNode]});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int v, e;
    cin >> v >> e;
    for (int i = 1; i <= e; ++i) {
        int u, v, w; cin >> u >> v >> w;
        map[u].push_back(make_pair(v, w));
        map[v].push_back(make_pair(u, w));
    }
    
    int m, x, s, y;
    cin >> m >> x;
    for (int i = 1; i <= m; ++i) {
        int tmp; cin >> tmp;
        dist_m[tmp] = 0;
        pq.push({tmp, 0});
    };
    Dijkstra(dist_m);
    
    cin >> s >> y;
    for (int i = 1; i <= s; ++i) {
        int tmp; cin >> tmp;
        dist_s[tmp] = 0;
        pq.push({tmp, 0});
    };
    Dijkstra(dist_s);

    int mini = 2*INF;
    for (int i = 1; i <= v; ++i) {
        if (dist_m[i] && dist_s[i] && dist_m[i] <= x && dist_s[i] <= y) {
            mini = min(mini, dist_m[i] + dist_s[i]);
        }
    }

    if (mini == 2*INF) cout << -1 << endl;
    else cout << mini << endl;

    return 0;
}