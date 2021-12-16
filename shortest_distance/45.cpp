#include <iostream>
#include <vector>
#include <queue>
#define INF 10000
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
    cin >> n >> m;
    vector<int> dist(n+1, INF);
    vector<int> prev(n+1);
    for (int i = 1; i <= m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        map[a].push_back(make_pair(b, c));
        map[b].push_back(make_pair(a, c));
    }
    
    dist[1] = 0;
    pq.push({1, 0});
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
                prev[nextNode] = node;
            }
        }
    }

    int cnt = 0;
    queue<pair<int, int> > Q;
    for (int i = 1; i <= n; ++i) {
        if (prev[i]) {
            cnt++;
            Q.push({i, prev[i]});
        }
    }
    cout << cnt << endl;
    while (!Q.empty()) {
        auto out = Q.front(); Q.pop();
        cout << out.first << ' ' << out.second << '\n';
    }

    return 0;
}