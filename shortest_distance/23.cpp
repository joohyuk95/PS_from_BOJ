#include <iostream>
#include <vector>
#include <queue>
#define INF 100000000
using namespace std;
vector<pair<int, int> > map[1001];

class Info {
public:
    int next, cost;
    
    Info(int a, int b) {
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
    int n, m, a, b, c, start, end;
    cin >> n >> m;
    vector<int> dist(n+1, INF);
    for (int i = 1; i <= m; ++i) {
        cin >> a >> b >> c;
        map[a].push_back(make_pair(b, c));
    }
    cin >> start >> end;
    
    pq.push(Info(start, 0));
    dist[start] = 0;
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
    cout << dist[end] << endl;
    return 0;
}