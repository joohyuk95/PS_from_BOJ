#include <iostream>
#include <vector>
#include <queue>
#define INF 2000000
using namespace std;

int n, m, a, b, c;
vector<pair<int, int> > map[100001];
int dist[100001];

class Info {
public:
    int node, cost;
    
    bool operator<(const Info &rhs) const {
        return this->cost > rhs.cost;
    }
};

bool Dijkstra(int k)
{
    for (int i = 1; i <= n; ++i) dist[i] = INF;
    priority_queue<Info> pq;
    pq.push({a, 0});
    dist[a] = 0;
    while (!pq.empty()) {
        int node = pq.top().node;
        int cost = pq.top().cost;
        pq.pop();
        if (dist[node] < cost) continue;
        
        for (int i = 0; i < map[node].size(); ++i) {
            int nextNode = map[node][i].first;
            int nextCost = map[node][i].second;
            if (nextCost <= k && dist[nextNode] > dist[node] + nextCost) {
                dist[nextNode] = dist[node] + nextCost;
                pq.push({nextNode, dist[nextNode]});
            }
        }
    }
    if (dist[b] <= c) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> a >> b >> c;
    for (int i = 1; i <= m; ++i) {
        int s, e, w; cin >> s >> e >> w;
        map[s].push_back({e, w});
        map[e].push_back({s, w});
    }

    int res = -1;
    int left = 0, right = 21;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (!Dijkstra(mid)) {
            left = mid + 1;
        } else {
            res = mid;
            right = mid - 1;
        }
    }
    cout << res << endl;

    return 0;
}