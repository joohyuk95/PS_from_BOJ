#include <iostream>
#include <vector>
#include <queue>
#define INF 200000
using namespace std;
int dist[20001];
vector<pair<int, int> > map[20001];

class Info {
public:
    int vertex;
    int weight;
    Info(int a, int b) {
        this->vertex = a;
        this->weight = b;
    }
    bool operator<(const Info &rhs) const {
        return this->weight > rhs.weight;
    }
};
priority_queue <Info> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    int v, e, k, a, b, c;
    cin >> v >> e >> k;
    for (int i = 1; i <= e; ++i) {
        cin >> a >> b >> c;
        map[a].push_back(make_pair(b, c));
    }
    for (int i = 1; i <= v; ++i) dist[i] = INF;
    dist[k] = 0;
    pq.push(Info(k, 0));

    while (!pq.empty()) {
        int ver = pq.top().vertex;
        int w = pq.top().weight;
        pq.pop();
        if (dist[ver] < w) continue;

        for (int i = 0; i < map[ver].size(); ++i) {
            int nextVertex = map[ver][i].first;
            int nextWeight = map[ver][i].second;
            if (dist[nextVertex] > dist[ver] + nextWeight) {
                dist[nextVertex] = dist[ver] + nextWeight;
                pq.push(Info(nextVertex, dist[nextVertex]));
            }
        }
    }
    for (int i = 1; i <= v; ++i) {
        if (dist[i] == INF) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }   
    return 0;
}