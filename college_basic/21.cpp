#include <iostream>
#include <vector>
using namespace std;

int r, c, res;
bool check[27];
char map[21][21];

int drow[4] = {-1, 0, 1, 0};
int dcol[4] = {0, 1, 0, -1};

void DFS(int row, int col, int cnt)
{
    int cur_idx = map[row][col] - 64;
    if (check[cur_idx]) {
        res = max(res, cnt - 1);
        return;
    }

    check[cur_idx] = true;
    for (int i = 0; i < 4; ++i) {
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if (0 < nrow && nrow <= r && 0 < ncol && ncol <= c) {
            DFS(nrow, ncol, cnt + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> r >> c;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            cin >> map[i][j];
        }
    }

    DFS(1, 1, 1);
    cout << res << endl;
    return 0;
}