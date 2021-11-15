#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> map[101];
queue<int> Q;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, k, a, b;
    cin >> n >> k;
    for (int i = 1; i <= k; ++i) {
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        vector<int> ch(n+1);
        vector<int> dist(n+1);
        Q.push(i);
        ch[i] = 1;
        while (!Q.empty()) {
            int tmp = Q.front(); Q.pop();
            for (int j = 0; j < map[tmp].size(); ++j) {
                if (!ch[map[tmp][j]]) {
                    ch[map[tmp][j]] = 1;
                    Q.push(map[tmp][j]);
                    dist[map[tmp][j]] = dist[tmp] + 1;
                    if (dist[map[tmp][j]] >= 7) {
                        cout << "Big World!" << endl;
                        exit(0);
                    }
                }
            }
        }
        for (int k = 1; k <= n; ++k) {
            if (i == k) continue;
            if (dist[k] == 0) {
                cout << "Big World!" << endl;
                exit(0);
            }
        }
    }
    cout << "Small World!" << endl;
    return 0;
}