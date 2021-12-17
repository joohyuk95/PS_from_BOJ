// 무방향 가중치 그래프
// 1번출발
// 늑대는 여우의 2, 0.5, 2 반복
// 여우가 늑대보다 먼저 도착할 수 있는 노드 몇 개?
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1000000000
#define MAX 4001

vector<pair<int, int> > map[4001];
int dist_fox[4001];
int dist_wolf[4001][2];

class Info {
public:
    int node, cost;
    bool operator<(const Info &rhs) const {
        return this->cost > rhs.cost;
    }
};

class wolf {
public:
    int node, cost, state;
    bool operator<(const wolf &rhs) const {
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
                pq.push({dist_fox[nextNode], nextCost});
            }
        }
    }
}

void Dijkstra_wolf()
{
    priority_queue<wolf> pq;
    pq.push({1, 1, 0});

    while (!pq.empty()) {
        int node = pq.top().node;
        int cost = pq.top().cost;
        int state = pq.top().state;
        pq.pop();

        for (int i = 0; i < map[node].size(); ++i) {
            if (state == 1) {
                int nextNode = map[node][i].first;
                int nextCost = map[node][i].second / 2;
                if (dist_wolf[state][nextNode] > dist_wolf[state][node] + nextCost) {
                    dist_wolf[state][nextNode] = dist_wolf[state][node] + nextCost;
                    pq.push({nextNode, dist_wolf[state][nextNode], 0});
                }
            }
            else if (state == 0) {
                int nextNode = map[node][i].first;
                int nextCost = map[node][i].second * 2;
                if (dist_wolf[state][nextNode] > dist_wolf[state][node] + nextCost) {
                    dist_wolf[state][nextNode] = dist_wolf[state][node] + nextCost;
                    pq.push({nextNode, dist_wolf[state][nextNode], 1});
                }
            }
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
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


    return 0;
}