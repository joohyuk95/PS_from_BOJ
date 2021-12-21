#include <iostream>
#include <stack>
#include <queue>
#include <vector>
using namespace std;

#define INF 10000000
#define MAX 1001

int n, m;
int node1, node2;
bool first = true;

vector<pair<int, int> > map[MAX];
int dist[MAX];
int pre[MAX];

class Info {
public:
    int node, cost;
    bool operator<(const Info &rhs) const {
        return this->cost > rhs.cost;
    }
};
priority_queue<Info> pq;

bool unlink(int a, int b)
{
    if (node1 == a && node2 == b) return true;
    else if (node1 == b && node2 == a) return true;
    return false;
}

int Dijkstra()
{
    for (int i = 1; i <= n; ++i) dist[i] = INF;
    dist[1] = 0;
    pq.push({1, 0});

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int node = cur.node;
        int cost = cur.cost;
        if (dist[node] < cost) continue;

        for (int i = 0; i < map[node].size(); ++i) {
            int nextNode = map[node][i].first;
            int nextCost = map[node][i].second;
            if (!first && unlink(node, nextNode)) continue;
            if (dist[nextNode] > dist[node] + nextCost) {
                dist[nextNode] = dist[node] + nextCost;
                pq.push({nextNode, dist[nextNode]});
                if (first) pre[nextNode] = node;
            }
        }
    }
    return dist[n];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int a, b, t; cin >> a >> b >> t;
        map[a].push_back(make_pair(b, t));
        map[b].push_back(make_pair(a, t));
    }
    
    int shortest = Dijkstra();
    first = false;

    int max_delay = 0;
    for (int i = n; i != 1; i = pre[i]) {
        node1 = i;
        node2 = pre[i];
        max_delay = max(max_delay, Dijkstra());
        if (max_delay == INF) {
            cout << -1 << endl;
            exit(0);
        }
    }
    cout << max_delay - shortest << endl;
    return 0;
}