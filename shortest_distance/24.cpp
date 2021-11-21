#include <iostream>
#include <vector>
#include <queue>
#define INF 10000000000
using namespace std;
vector<pair<int, int> > map[100000];

class Info {
public:
    int next;
    int cost;
    
    Info (int a, int b) {
        this->next = a;
        this->cost = b;
    }
    bool operator<(const Info &rhs) const {
        return this->cost > rhs.cost;
    }
};
priority_queue<Info> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m, a, b, c;
    cin >> n >> m;
    vector<int> remove(n);
    vector<long long> dist(n, INF);
    for (int i = 0; i < n; ++i) {
        cin >> remove[i];
    }
    remove[n-1] = 0;
    for (int i = 1; i <= m; ++i) {
        cin >> a >> b >> c;
        if (!remove[a] && !remove[b]) {
            map[a].push_back(make_pair(b, c));
            map[b].push_back(make_pair(a, c));
        }
    }

    pq.push(Info(0, 0));
    dist[0] = 0;
    while (!pq.empty()) {
        int node = pq.top().next;
        int nodeCost = pq.top().cost;
        pq.pop();
        if (dist[node] < nodeCost) continue;

        for (int i = 0; i < map[node].size(); ++i) {
            int nextNode = map[node][i].first;
            int nextCost = map[node][i].second;
            if (dist[nextNode] > dist[node] + nextCost) {
                dist[nextNode] = dist[node] + nextCost;
                pq.push(Info(nextNode, dist[nextNode]));
            }
        }
    }

    if (dist[n-1] == INF) cout << -1 << endl;
    else cout << dist[n-1] << endl;
    return 0;
}