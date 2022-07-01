#include <iostream>
using namespace std;

int n, m, ans;
int map[5][5];
bool visit[5][5];

void DFS(int row, int col)
{
    if (row == 5) {
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            int tmp = 0;
            for (int j = 1; j <= m; ++j) {
                if (visit[i][j]) tmp = tmp*10 + map[i][j];
                else {
                    sum += tmp;
                    tmp = 0;
                }
            }
            sum += tmp;
        }
        for (int j = 1; j <= m; ++j) {
            int tmp = 0;
            for (int i = 1; i <= n; ++i) {
                if (!visit[i][j]) tmp = tmp*10 + map[i][j];
                else {
                    sum += tmp;
                    tmp = 0;
                }
            }
            sum += tmp;
        }
        ans = (ans > sum) ? ans : sum;
        return;
    }
    if (col == 5) {
        DFS(row + 1, 1);
        return;
    }

    visit[row][col] = true;
    DFS(row, col + 1);
    visit[row][col] = false;
    DFS(row, col + 1);
}

int main()
{
    cin >> n >> m;
    string str;
    for (int i = 1; i <= n; ++i) {
        cin >> str;
        for (int j = 1; j <= m; ++j) {
            map[i][j] = str[j-1] - '0';
        }
    }

    DFS(1, 1);
    cout << ans << '\n';

    return 0;
}