#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 2000000
#define MAX 2001

vector<pair<int, int> > map[MAX];
vector<int> candi;
int dist_s[MAX];
int dist_g[MAX];
int dist_h[MAX];

class Info {
public:
    int node, cost;
    bool operator<(const Info &rhs) const {
        return this->cost > rhs.cost;
    }
};
priority_queue<Info> pq;

void Dijkstra(int start, int dist[MAX])
{
    dist[start] = 0;
    pq.push({start, 0});
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
}

int main()
{
    ios_base::sync_with_stdio(false);
    int T; cin >> T;
    for (int k = 1; k <= T; ++k) {
        int n, m, t;
        int s, g, h;
        cin >> n >> m >> t >> s >> g >> h;
        for (int i = 0; i < MAX; ++i) {
            map[i].clear();
            dist_s[i] = INF;
            dist_g[i] = INF;
            dist_h[i] = INF;
        }
        candi.clear();
        for (int i = 1; i <= m; ++i) {
            int a, b, d; cin >> a >> b >> d;
            map[a].push_back(make_pair(b, d));
            map[b].push_back(make_pair(a, d));
        }
        for (int i = 1; i <= t; ++i) {
            int a; cin >> a;
            candi.push_back(a);
        }

        Dijkstra(s, dist_s);
        Dijkstra(g, dist_g);
        Dijkstra(h, dist_h);
        sort(candi.begin(), candi.end());

        for (int i = 0; i < candi.size(); ++i) {
            int dest = candi[i];
            if (dist_s[dest] - dist_g[h] == dist_s[g] + dist_h[dest]) cout << dest << ' ';
            else if (dist_s[dest] - dist_g[h] == dist_s[h] + dist_g[dest]) cout << dest << ' ';
        }
        cout << '\n';
    }

    return 0;
}