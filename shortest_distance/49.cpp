// 방향 그래프, 여러번 방문가능 (사이클 가능)
// 음의 가중치 가능
// 도시번호 0번부터 n-1까지, n, m <= 50
// 무한대로 벌 수 있음과 음의 사이클 상관관계
// 보통은 cost minimizing인데 여기서는 가진 돈을 최대화 하는게 목표임
// 그래서 earn할수록 이득임.
// 최소화하려면 가중치는 양의 무한대 였겠으나
// 여기서는 maximize이므로 음의 무한대로 설정하는 것이 상식적임.

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

#define MAX 50
#define INF -25000000000

int n, s, e, m;

int earn[MAX];
bool visit[MAX];
vector<long long> dist(n+1, LONG_MIN);
vector<pair<int, int> > map[MAX];

void DFS(int now)
{
    visit[now] = true;
    for (int i = 0; i < map[now].size(); ++i) {
        if (visit[map[now][i].first] == false) {
            DFS(map[now][i].first);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> s >> e >> m;

    for (int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        map[u].push_back({v, -w});
    }
    for (int i = 0; i < n; ++i) {
        cin >> earn[i];
    }

    DFS(s);
    if (visit[e] == false) {
        cout << "gg" << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < map[i].size(); ++j) {
            map[i][j].second += earn[map[i][j].first];
        }
    }

    dist[s] = earn[s];
    for (int i = 1; i <= 2 * n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (auto cur : map[j]) {
                int next = cur.first;
                long long nextCost = cur.second;
                if (dist[j] == LONG_MAX) dist[next] = LONG_MAX;
                else if (dist[j] != LONG_MIN && dist[next] < dist[j] + nextCost) {
                    dist[next] = dist[j] + nextCost;
                    if (i >= n) dist[next] = LONG_MAX;
                }
            }
        }
    }
    if (dist[e] == LONG_MAX) cout << "Gee" << endl;
    else cout << dist[e] << endl;
    return 0;
}