#include <iostream>
#include <cstdio>
#include <deque>
using namespace std;
int map[101][101];
int visit[101][101];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

struct Info {
    int x, y, cnt;
};

int main()
{
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%1d", &map[i][j]);
        }
    }

    deque<Info> dq;
    dq.push_back({1, 1, 0});
    visit[1][1] = 1;
    while (!dq.empty()) {
        Info cur = dq.front(); dq.pop_front();
        int row = cur.x;
        int col = cur.y;
        int cnt = cur.cnt;
        if (row == n && col == m) {
            cout << cnt << endl;
            break;
        }
        for (int i = 0; i < 4; ++i) {
            int nextRow = row + dx[i]; 
            int nextCol = col + dy[i];
            if (nextRow < 1 || nextRow > n || nextCol < 1 || nextCol > m) continue;
            if (visit[nextRow][nextCol]) continue;
            
            visit[nextRow][nextCol] = 1;
            if (map[nextRow][nextCol]) dq.push_back({nextRow, nextCol, cnt + 1});
            else dq.push_front({nextRow, nextCol, cnt});
        }
    }
    return 0;
}