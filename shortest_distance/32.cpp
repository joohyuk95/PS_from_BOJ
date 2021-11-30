#include <iostream>
#include <vector>
#include <queue>
#define INF 200000000
using namespace std;
int n, m, p, q, z;
vector<pair<int, int> > map[801];

class Info {
public:
    int node;
    int cost;

    Info(int a, int b) {
        this->node = a;
        this->cost = b;
    }
    bool operator<(const Info &rhs) const {
        return this->cost > rhs.cost;
    }
};
priority_queue<Info> pq;

int Dijkstra(int start, int end)
{
    if (start == end) return 0;
    vector<int> dist(n+1, INF);
    dist[start] = 0;
    pq.push(Info(start, 0));
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
                pq.push(Info(nextNode, dist[nextNode]));
            }
        }
    }
    if (dist[end] == INF) return -1;
    else return dist[end];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        map[a].push_back(make_pair(b, c));
        map[b].push_back(make_pair(a, c));
    }
    cin >> p >> q;

    int x1 = Dijkstra(1, p), y1 = Dijkstra(q, n);
    int x2 = Dijkstra(1, q), y2 = Dijkstra(p, n);
    int z = Dijkstra(p, q);
    int ptoq = x1 + z + y1;
    int qtop = x2 + z + y2;
    int min = (ptoq > qtop) ? qtop : ptoq;
    if (x1 == -1 || y1 == -1 || z == -1) cout << -1 << endl;
    else cout << min << endl;

    return 0;
}