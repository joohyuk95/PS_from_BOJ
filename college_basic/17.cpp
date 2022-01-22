#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX 50

int n, m, ans;

char map[MAX][MAX];
int visit[MAX][MAX];

int drow[4] = {-1, 0, 1, 0};
int dcol[4] = {0, 1, 0, -1};

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
        }
    }
}

int BFS(int r, int c)
{
    int tmp = 0;
    queue<pair<int, int> > Q;
    Q.push({r, c});
    visit[r][c] = 0;

    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        int row = cur.first;
        int col = cur.second;

        if (visit[row][col] > tmp) tmp = visit[row][col];
        for (int i = 0; i < 4; ++i) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow == r && ncol == c) continue;
            if (0 <= nrow && nrow < n && 0 <= ncol && ncol < m) {
                if (!visit[nrow][ncol] && map[nrow][ncol] == 'L') {
                    Q.push({nrow, ncol});
                    visit[nrow][ncol] = visit[row][col] + 1;
                }
            }
        }
    }
    return tmp;
}

void solution()
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (map[i][j] == 'L') {
                int R = BFS(i, j);
                ans = max(ans, R);
                memset(visit, 0, sizeof(visit));
            }
        }
    }
    cout << ans << endl;
}

void solve()
{
    input();
    solution();
}

int main()
{
    ios_base::sync_with_stdio(false);
    solve();

    return 0;
}