#include <iostream>
using namespace std;

int n, ans = 1e7;
int map[11][11];
bool check[11];

void move(int start, int idx, int cnt, int cost)
{
    if (cnt == n) {
        int last_cost = map[idx][start];
        if (last_cost == 0) return;
        if (ans > cost + last_cost) ans = cost + last_cost;
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (check[i] || map[idx][i] == 0) continue;
        check[i] = true;
        move(start, i, cnt + 1, cost + map[idx][i]);
        check[i] = false;
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> map[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        check[i] = true;
        move(i, i, 1, 0);
        check[i] = false;
    }

    cout << ans << '\n';
    return 0;
}