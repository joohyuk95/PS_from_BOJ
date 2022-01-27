#include <iostream>
#include <vector>
using namespace std;

int r, c, res;
bool check[26];
char map[21][21];

int drow[4] = {-1, 0, 1, 0};
int dcol[4] = {0, 1, 0, -1};

void DFS(int row, int col, int cnt)
{
    res = max(res, cnt);

    for (int i = 0; i < 4; ++i) {
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if (0 < nrow && nrow <= r && 0 < ncol && ncol <= c) {
            char next_char = map[nrow][ncol] - 'A';
            if (check[next_char] == false) {
                check[next_char] = true;
                DFS(nrow, ncol, cnt + 1);
                check[next_char] = false;
            }
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

    check[map[1][1] - 'A'] = true;
    DFS(1, 1, 1);
    cout << res << endl;
    return 0;
}