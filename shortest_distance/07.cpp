#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int> > map(101, vector<int> (101, 1500));
vector<int> item(101);
priority_queue<int> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m, r, a, b, c, sum;
    cin >> n >> m >> r;
    for (int i = 1; i <= n; ++i) {
        cin >> item[i];
    }
    for (int i = 1; i <= r; ++i) {
        cin >> a >> b >> c;
        map[a][b] = c;
        map[b][a] = c;
    }
    for (int i = 1; i <= n; ++i) map[i][i] = 0;
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        sum = 0;
        for (int j = 1; j <= n; ++j) {
            if (map[i][j] <= m) sum += item[j];
        }
        pq.push(sum);
    }
    cout << pq.top() << endl;
    return 0;
}