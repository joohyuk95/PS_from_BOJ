#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int> > map(n+1, vector<int> (n+1));
    vector<vector<int> > res(n+1, vector<int> (n+1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> map[i][j];
            res[i][j] = map[i][j];
        }
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == j || j == k || k == i) continue;
                if (map[i][j] > map[i][k] + map[k][j]) {
                    cout << -1 << endl;
                    return 0;
                }
                else if (map[i][j] == map[i][k] + map[k][j]) {
                    res[i][j] = 0;
                }
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            cnt += res[i][j]; 
        }
    }
    cout << cnt / 2 << endl;
    return 0;
}