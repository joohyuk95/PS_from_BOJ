#include <iostream>
using namespace std;

int m, n;
int map[501][501];
int dp[501][501];

int drow[4] = {-1, 0, 1, 0};
int dcol[4] = {0, 1, 0, -1};

int DFS(int row, int col)
{
    if (row == m && col == n) return 1;
    if (dp[row][col] != -1) return dp[row][col];

    dp[row][col] = 0;
    for (int i = 0; i < 4; ++i) {
        int nrow = row + drow[i];
        int ncol = col + dcol[i];
        if (nrow < 1 || nrow > m || ncol < 1 || ncol > n) continue;
        if (map[nrow][ncol] < map[row][col]) {
            dp[row][col] += DFS(nrow, ncol);
        }
    }
    return dp[row][col];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> m >> n;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = -1;
            cin >> map[i][j];
        }
    }

    cout << DFS(1, 1) << '\n';
    return 0;
}