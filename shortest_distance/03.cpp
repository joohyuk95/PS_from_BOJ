#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int> > map(53, vector<int> (53, 1000));

int alpha2num(char x)
{
    if (x >= 65 && x < 91) return x - 64;
    else return x - 70;
}

char num2aplpha(int x)
{
    if (x >= 1 && x <= 26) return char(x + 64);
    else return char(x + 70);
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n, p, q, cnt = 0;
    char a[5];
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> a[j];
        }
        p = alpha2num(a[0]);
        q = alpha2num(a[3]);
        map[p][q] = 1;
    }

    for (int k = 1; k <= 52; ++k) {
        for (int i = 1; i <= 52; ++i) {
            for (int j = 1; j <= 52; ++j) {
                if (i == j) continue;
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }
    queue<pair<int, int> > Q;
    for (int i = 1; i <= 52; ++i) {
        for (int j = 1; j <= 52; ++j) {
            if (map[i][j] != 1000) {
                cnt++;
                Q.push(make_pair(i, j));
            }
        }
    }
    cout << cnt << endl;
    while (!Q.empty()) {
        cout << num2aplpha(Q.front().first) << " => " << num2aplpha(Q.front().second) << endl;
        Q.pop();
    }
    return 0;
}