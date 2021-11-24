#include <iostream>
#include <vector>
#include <queue>
#define MAX 2147000000
using namespace std;
int map[11][11], ch[11];
int n, m, s, e, c;
int res = MAX;

void backTrack(int ver, int total, int maxCost)
{
    if (total > c) return;
    if (ver == e) {
        res = min(res, maxCost);
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (!map[ver][i] || ch[i]) continue;
        ch[i] = 1;
        backTrack(i, total + map[ver][i], max(maxCost, map[ver][i]));
        ch[i] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> s >> e >> c;
    for (int i = 1; i <= m; ++i) {
        int A, B, C;
        cin >> A >> B >> C;
        map[A][B] = C;
        map[B][A] = C;
    }

    backTrack(s, 0, 0);
    if (res == MAX) cout << -1 << endl;
    else cout << res << endl;
    
    return 0;
}