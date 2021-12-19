#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1000000000
#define MAX 4001

vector<pair<int, int> > map[MAX];
int dist_fox[MAX];
int dist_wolf[2][MAX];

class Info {
public:
<<<<<<< Updated upstream
    int node, cost;
    bool state;

    Info(int a, int b, bool c = 0) {
=======
    int node, cost, state;
    
    Info (int a, int b, int c = 0) {
>>>>>>> Stashed changes
        this->node = a;
        this->cost = b;
        this->state = c;
    }
<<<<<<< Updated upstream

=======
    
>>>>>>> Stashed changes
    bool operator<(const Info &rhs) const {
        return this->cost > rhs.cost;
    }
};

void Dijkstra_fox()
{
    priority_queue<Info> pq;
    pq.push({1, 0});
    dist_fox[1] = 0;

    while (!pq.empty()) {
        int node = pq.top().node;
        int cost = pq.top().cost;
        pq.pop();
        if (dist_fox[node] < cost) continue;

        for (int i = 0; i < map[node].size(); ++i) {
            int nextNode = map[node][i].first;
            int nextCost = map[node][i].second;
            if (dist_fox[nextNode] > dist_fox[node] + nextCost) {
                dist_fox[nextNode] = dist_fox[node] + nextCost;
                pq.push({nextNode, dist_fox[nextNode]});
            }
        }
    }
}

void Dijkstra_wolf()
{
    priority_queue<Info> pq;
<<<<<<< Updated upstream
    pq.push({1, 0, 1});
=======
    pq.push({1, 1, 0});
>>>>>>> Stashed changes

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int node = cur.node;
        int cost = cur.cost;
        int state = cur.state;
        if (dist_wolf[!state][node] < cost) continue;

        for (int i = 0; i < map[node].size(); ++i) {
            int nextNode = map[node][i].first;
            int nextCost = map[node][i].second;
            if (state) nextCost /= 2;
            else nextCost *= 2;
                
            if (dist_wolf[state][nextNode] > cost + nextCost) {
                dist_wolf[state][nextNode] = cost + nextCost;
                if (state) pq.push({nextNode, dist_wolf[state][nextNode], !state});
                else pq.push({nextNode, dist_wolf[state][nextNode], !state});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int a, b, d; cin >> a >> b >> d;
        map[a].push_back(make_pair(b, d*2));
        map[b].push_back(make_pair(a, d*2));
    }
    for (int i = 1; i <= n; ++i) {
        dist_fox[i] = INF;
        dist_wolf[0][i] = INF;
        dist_wolf[1][i] = INF;
    }

    Dijkstra_fox();
    Dijkstra_wolf();

    int cnt = 0;
    for (int i = 2; i <= n; ++i) {
        if (dist_fox[i] == INF) continue;
        if (dist_fox[i] < min(dist_wolf[0][i], dist_wolf[1][i])) {
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}