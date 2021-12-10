#include <iostream>
#include <queue>
#include <vector>
#define INF 1000000
using namespace std;

vector<pair<int, int> > map[1001];

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
    int n, m;
    int a, b, k, g;
    cin >> n >> m >> a >> b >> k >> g;
    vector<int> g_path(g+1);
    vector<int> dist(n+1, INF);
    vector<vector<int> > weight(n+1, vector<int> (n+1));
    vector<vector<pair<int, int> > > control(n+1, vector<pair<int, int> > (n+1));

    for (int i = 1; i <= g; ++i) {
        cin >> g_path[i];
    }
    for (int i = 1; i <= m; ++i) {
        int u, v, l; cin >> u >> v >> l;
        map[u].push_back(make_pair(v, l));
        map[v].push_back(make_pair(u, l));
        weight[u][v] = l;
        weight[v][u] = l;
    }

    int time = 0;
    for (int i = 1; i < g; ++i) {
        int u = g_path[i];
        int v = g_path[i + 1];
        int w = weight[u][v];
        control[u][v] = make_pair(time, time + w);
        control[v][u] = control[u][v];
        time += w;
    }

    dist[a] = k;
    pq.push({a, k});
    while (!pq.empty()) {
        int node = pq.top().node;
        int cost = pq.top().cost;
        pq.pop();
        
        for (int i = 0 ; i < map[node].size(); ++i) {
            int nextNode = map[node][i].first;
            int nextCost = map[node][i].second;
            auto C = control[node][nextNode];
            if (C.first <= cost && cost <= C.second) {
                nextCost += C.second - cost;
            }
            if (dist[nextNode] > dist[node] + nextCost) {
                dist[nextNode] = dist[node] + nextCost;
                pq.push({nextNode, dist[nextNode]});
            }
        }
    }
    cout << dist[b] - k << endl;

    return 0;
}