#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int drow[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dcol[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int main()
{
    ios_base::sync_with_stdio(false);
    int tc;
    cin >> tc;

    for (int i = 1; i <= tc; ++i) {
        int l, srow, scol, erow, ecol;
        cin >> l >> srow >> scol >> erow >> ecol;
        if (srow == erow && scol == ecol) {
            cout << 0 << endl;
            continue;
        }
        vector<vector<int> > map(l, vector<int> (l));
        vector<vector<int> > cnt(l, vector<int> (l));
        queue<pair<int, int> > Q;
        
        Q.push({srow, scol});
        while (!Q.empty()) {
            auto cur = Q.front(); Q.pop();
            int row = cur.first;
            int col = cur.second;

            for (int i = 0; i < 8; ++i) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if (0 <= nrow && nrow < l && 0 <= ncol && ncol < l) {
                    if (!cnt[nrow][ncol]) {
                        cnt[nrow][ncol] = cnt[row][col] + 1;
                        Q.push({nrow, ncol});
                    }
                }
            }
        }
        cout << cnt[erow][ecol] << endl;
    }

    return 0;
}