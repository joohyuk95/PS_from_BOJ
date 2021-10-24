#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> map[300001];

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m, k, x, a, b, tmp;
    cin >> n >> m >> k >> x;
    vector<int> dist(n+1);
    vector<int> ch(n+1);
    queue<int> Q;
    for (int i = 1; i <= m; ++i) {
        cin >> a >> b;
        map[a].push_back(b);
    }
    Q.push(x);
    ch[x] = 1;
    while (!Q.empty()) {
        tmp = Q.front();
        Q.pop();
        for (int i = 0; i < map[tmp].size(); ++i) {
            if (ch[map[tmp][i]] == 0) {
                ch[map[tmp][i]] = 1;
                Q.push(map[tmp][i]);
                dist[map[tmp][i]] = dist[tmp] + 1;
            }
        }
    }

    bool flag = false;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == k) {
            flag = true;
            cout << i << endl;
        }
    }
    if (!flag) cout << -1 << endl;
    return 0;
}