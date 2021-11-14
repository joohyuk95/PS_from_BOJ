#include <iostream>
#include <vector>
using namespace std;
int map[401][401];

int main()
{
    ios_base::sync_with_stdio(false);
    int n, k, a, b, s;
    cin >> n >> k;
    for (int i = 1; i <= k; ++i) {
        cin >> a >> b;
        map[a][b] = 1;
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (map[i][k] && map[k][j]) map[i][j] = 1;
            }
        }
    }

    cin >> s;
    vector<pair<int, int> > ask(s+1);
    for (int i = 1; i <= s; ++i) {
        cin >> a >> b;
        ask[i] = make_pair(a, b);
    }
    for (int i = 1; i <= s; ++i) {   
        a = ask[i].first; 
        b = ask[i].second;
        if (map[a][b]) cout << -1 << "\n";
        else if (map[b][a]) cout << 1 << "\n";
        else cout << 0 << "\n";
    }
    return 0;
}