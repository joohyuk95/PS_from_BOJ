#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 50
#define MAX 51

int res1, res2;
int s_row, s_col, e_row, e_col;

char map[MAX][MAX];
int dist[MAX][MAX];
int drow[] = {-1, 0, 1, 0};
int dcol[] = {0, 1, 0, -1};

class Info {
public:
    int row, col, step, side;

    bool operator<(const Info &rhs) const {
        if (this->step == rhs.step) return this->side > rhs.side;
        else return this->step > rhs.step;
    }
};
priority_queue<Info> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> map[i][j];
            if (map[i][j] == 'S') {
                s_row = i;
                s_col = j;
            } else if (map[i][j] = 'F') {
                e_row = i;
                e_col = j;
            }
            dist[i][j] = INF;
        }
    }

    pq.push({s_row, s_col, 0, 0});
    dist[s_row][s_col] = 0;
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int row = cur.row;
        int col = cur.col;
        int step = cur.step;
        int side = cur.side;

        bool end = false;
        for (int i = 0; i < 4; ++i) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            if (nrow == e_row && ncol == e_col) {
                end = true;
                res1 = step;
                res2 = side;
                break;
            }

            if (nrow < 1 || nrow > n || ncol < 1 || ncol > n) continue;
            if (dist[nrow][ncol] != INF) continue;

            if (map[nrow][ncol] == 'g') {
                pq.push({nrow, ncol, step + 1, side});
            }
            else if (map[nrow][ncol] == '.') {
                bool flag = false;
                for (int j = 0; j < 4; ++j) {
                    if (map[nrow + drow[i]][ncol + dcol[i]] == 'g') {
                        flag = true;
                        pq.push({nrow, ncol, step, side + 1});
                    }
                }
                if (!flag) pq.push({nrow, ncol, step, side});
            }
            dist[nrow][ncol] = dist[row][col] + 1;
        }
        if (end) break;
    }
    cout << res1 << ' ' << res2 << endl;
    return 0;
}