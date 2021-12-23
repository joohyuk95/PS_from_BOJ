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
#include <queue>
using namespace std;

#define MAX 50
#define INF 25000000000

int n, m, s, e;

int earn[MAX];
bool visit[MAX];
vector<long long> dist(n+1, INF);
vector<pair<int, int> > map[MAX];
queue<int> cycleNode;

bool BFS()  // BFS 어떻게 함?
{
    while (!cycleNode.empty()) {
        int cur = cycleNode.front(); cycleNode.pop();

        for (auto x : map[cur]) {
            int next = x.first;
            if (visit[next]) continue;
            visit[next] = true;
            cycleNode.push(next);
        }
    }
    if (visit[e]) return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> s >> e >> m;

    for (int i = 0; i < m; ++i) {
        int u, v, w; cin >> u >> v >> w;
        map[u].push_back({v, w});
    }
    for (int i = 0; i < n; ++i) {
        cin >> earn[i];
    }

    dist[s] = -earn[s];
    for (int i = 1; i <= 2 * n; ++i) {  /// 왜 2n까지인지
        for (int j = 0; j < n; ++j) {
            for (auto cur : map[j]) {
                int next = cur.first;
                long long nextCost = cur.second;
                if (dist[j] != INF && dist[next] > dist[j] + nextCost - earn[next]) {
                    dist[next] = dist[j] + nextCost - earn[next];
                    if (i == n) { // 이게 왜 싸이클 판별인지
                        visit[j] = true; cycleNode.push(j);
                    }
                }
            }
        }
    }
    
    if (dist[e] == INF) cout << "gg" << endl;
    else {
        if (BFS()) cout << "Gee" << endl;
        else cout << -dist[e] << endl;
    }
    return 0;
}