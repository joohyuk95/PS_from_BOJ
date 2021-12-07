#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define INF 100000000
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
stack<int> S;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m, s, e;
    cin >> n >> m;
    vector<int> dist(n+1, INF);
    vector<int> prev(n+1);
    for (int i = 1; i <= m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        map[a].push_back(make_pair(b, c));
    }
    cin >> s >> e;

    dist[s] = 0;
    pq.push({s, 0});
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

    int end = e;
    int cnt = 1;
    while (true) {
        S.push(end);
        cnt++;
        end = prev[end];
        if (end == s) {
            S.push(s);
            break;
        }
    }

    cout << dist[e] << endl << cnt << endl;
    while (!S.empty()) {
        cout << S.top() << ' ';
        S.pop();
    }
    cout << endl;
    return 0;
}