#include <iostream>
#include <vector>
#include <queue>
#define INF 100000000
using namespace std;

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
    int t, n, d, c;
    cin >> t;
    queue<pair<int, int> > Q;
    for (int i = 1; i <= t; ++i) {
        vector<pair<int, int> > map[10001];
        cin >> n >> d >> c;
        vector<int> dist(n+1, INF);
        for (int j = 1; j <= d; ++j) {
            int a, b, s; cin >> a >> b >> s;
            map[b].push_back(make_pair(a, s));
        }
        dist[c] = 0;
        pq.push({c, 0});

        while (!pq.empty()) {
            int node = pq.top().node;
            int cost = pq.top().cost;
            pq.pop();
            if (dist[node] < cost) continue;

            for (int k = 0; k < map[node].size(); ++k) {
                int nextNode = map[node][k].first;
                int nextCost = map[node][k].second;
                if (dist[nextNode] > dist[node] + nextCost) {
                    dist[nextNode] = dist[node] + nextCost;
                    pq.push({nextNode, dist[nextNode]});
                }
            }
        }
        
        int max = 0, cnt = n;
        for (int j = 1; j <= n; ++j) {
            if (dist[j] == INF) cnt--;
            else if (dist[j] > max) max = dist[j];
        }
        Q.push(make_pair(cnt, max));
    }

    while (!Q.empty()) {
        cout << Q.front().first << ' ' << Q.front().second << endl;
        Q.pop();
    }
    return 0;
}