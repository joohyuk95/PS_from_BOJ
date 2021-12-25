#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1e15

int n, m, A, B;
long long C;

long long dist[100001];
vector<pair<int, long long> > map[100001];

class Info {
public:
    int node;
    long long cost;
    bool operator<(const Info &rhs) const {
        return this->cost > rhs.cost;
    }
};

bool Dijkstra(long long remain)
{
    for (int i = 1; i <= n; ++i) dist[i] = INF;
    priority_queue<Info> pq;
    
    pq.push({A, 0});
    dist[A] = 0;
    while (!pq.empty()) {
        int node = pq.top().node;
        long long cost = pq.top().cost;
        pq.pop();
        if (dist[node] < cost) continue;
        
        for (auto cur : map[node]) {
            int nextNode = cur.first;
            long long nextCost = cur.second;
            if (remain >= nextCost && dist[nextNode] > dist[node] + nextCost) {
                dist[nextNode] = dist[node] + nextCost;
                pq.push({nextNode, dist[nextNode]});
            }
        }
    }
    if (dist[B] <= C) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> A >> B >> C;
    for (int i = 1; i <= m; ++i) {
        long long u, v, w; cin >> u >> v >> w;
        map[u].push_back({v, w});
        map[v].push_back({u, w});
    }

    long long ans = -1;
    long long left = 0, right = INF;
    while (left <= right) {
        long long mid = (left + right) / 2;
        if (!Dijkstra(mid)) {
            left = mid + 1;
        } else {
            ans = mid;
            right = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}