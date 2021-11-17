#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<int> > map(n+1, vector<int> (n+1, 100));
    vector<int> bacon(n+1);
    for (int i = 1; i <= m; ++i) {
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }    
    for (int i = 1; i <= n; ++i) map[i][i] = 0;
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            int cnt = 0;
            for (int j = 1; j <= n; ++j) {
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
                cnt += map[i][j];
            }
            bacon[i] = cnt;
        }
    }

    int index, mini = 100;
    for (int i = 1; i <= n; ++i) {
        if (bacon[i] < mini) {
            mini = bacon[i];
            index = i;
        }
    }
    cout << index << endl;
    return 0;
}