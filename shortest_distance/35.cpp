#include <iostream>
#include <queue>
#include <vector>
#define INF 50000000
using namespace std;
int v, e, p, sum;
vector<pair<int, int> > map[5001];

class Info {
public:
    int node, cost;

    bool operator<(const Info &rhs) const {
        return this->cost > rhs.cost;
    }
};
priority_queue<Info> pq;

int Dijkstra (int start, int end)
{
    vector<int> dist(v+1, INF);
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
    sum += dist[p];
    return dist[end];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> v >> e >> p;
    for (int i = 1; i <= e; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        map[a].push_back(make_pair(b, c));
        map[b].push_back(make_pair(a, c));
    }
    
    int to_n = Dijkstra(1, v);
    int to_1 = Dijkstra(v, 1);
    if (to_n >= sum) cout << "SAVE HIM" << endl;
    else cout << "GOOD BYE" << endl;

    return 0;
}