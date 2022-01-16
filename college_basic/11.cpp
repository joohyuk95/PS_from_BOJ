#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, ans1, ans2;
char map[101][101];
bool visit[101][101];

int drow[4] = {-1, 0, 1, 0};
int dcol[4] = {0, 1, 0, -1};

void BFS(int x, int y)
{
    queue<pair<int, int> > Q;
    Q.push({x, y});
    visit[x][y] = true;

    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        int row = cur.first;
        int col = cur.second;
        
        for (int i = 0; i < 4; ++i) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];
            if (nrow < 1 || nrow > n || ncol < 1 || ncol > n) continue;
            if (!visit[nrow][ncol] && map[nrow][ncol] == map[x][y]) {
                visit[nrow][ncol] = true;
                Q.push({nrow, ncol});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> map[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (!visit[i][j]) {
                BFS(i, j);
                ans1++;
            }
        }
    }

    memset(visit, false, sizeof(visit));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (map[i][j] == 'G') map[i][j] = 'R';
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (!visit[i][j]) {
                BFS(i, j);
                ans2++;
            }
        }
    }

    cout << ans1 << ' ' << ans2 << endl;
    return 0;
}