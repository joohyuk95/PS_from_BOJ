#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> map[1001];
bool visit[1001];

void BFS(int start)
{
    queue<int> Q;
    if (visit[start]) return;
    
    visit[start] = true;
    Q.push(start);
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for (int i = 0; i < map[cur].size(); ++i) {
            if (!visit[map[cur][i]]) {
                visit[map[cur][i]] = true;
                Q.push(map[cur][i]);
            }
        }
    } 
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int a, b; cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }

    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (visit[i]) continue;
        cnt++;
        BFS(i);
    }
    cout << cnt << endl;
    return 0;
}