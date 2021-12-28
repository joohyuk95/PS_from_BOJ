#include <iostream>
#include <queue>
using namespace std;

#define MAX 26

int n, complex_cnt, house_cnt;

char map[MAX][MAX];
int complex[MAX][MAX];

int drow[] = {-1, 0, 1, 0};
int dcol[] = {0, 1, 0, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> map[i][j];
            map[i][j] -= 48;
        }
    }

    queue<pair<int, int> > Q;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (map[i][j]) {                
                Q.push({i, j});
                map[i][j] = 0;
                house_cnt = 1;
                while (!Q.empty()) {
                    auto cur = Q.front(); Q.pop();
                    int row = cur.first;
                    int col = cur.second;
                    for (int k = 0; k < 4; ++k) {
                        int nrow = row + drow[k];
                        int ncol = col + dcol[k];
                        if (nrow > n || nrow < 1 || ncol > n || ncol < 1) continue;
                        if (map[nrow][ncol]) {
                            Q.push({nrow, ncol});
                            map[nrow][ncol] = 0;
                            house_cnt++;
                        }
                    }
                }
                complex_cnt++;
                pq.push(house_cnt);
            }
        }
    }

    cout << complex_cnt << '\n';
    while (!pq.empty()) {
        cout << pq.top() << '\n';
        pq.pop();
    }
    return 0;
}