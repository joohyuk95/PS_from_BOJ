#include <iostream>
#include <vector>
#include <queue>
#define INF 500000
using namespace std;
vector<pair<int, int> > map[5001];

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

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m, a, b, c, s, t;
    cin >> n >> m;
    vector<int> dist(n+1, INF);
    for (int i = 1; i <= m; ++i) {
        cin >> a >> b >> c;
        map[a].push_back(make_pair(b, c));
        map[b].push_back(make_pair(a, c));
    }
    cin >> s >> t;
    
    dist[s] = 0;
    pq.push(Info(s, 0));
    while (!pq.empty()) {
        int node = pq.top().node;
        int cost = pq.top().cost;
        pq.pop();
        
        for (int i = 0; i < map[node].size(); ++i) {
            int nextNode = map[node][i].first;
            int nextCost = map[node][i].second;
            if (dist[nextNode] > dist[node] + nextCost) {
                dist[nextNode] = dist[node] + nextCost;
                pq.push(Info(nextNode, dist[nextCost]));
            }
        }
    }
    cout << dist[t] << endl;

    return 0;
}