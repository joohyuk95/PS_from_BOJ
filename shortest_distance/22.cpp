#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    char a;
    cin >> n;
    vector<vector<int> > map(n+1, vector<int> (n+1, 100));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a;
            if (i == j) map[i][j] = 0;
            if (a == 'Y') map[i][j] = 1;
        } 
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }

    int max = 0;
    for (int i = 1; i <= n; ++i) {
        int cnt = 0;
        for (int j = 1; j <= n; ++j) {
            if (map[i][j] == 1 || map[i][j] == 2) cnt++;
        }
        if (cnt > max) max = cnt;
    }
    cout << max << endl;

    return 0;
}