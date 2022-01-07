#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    char info;
    cin >> n;
    vector<vector<int> > map(n+1, vector<int> (n+1));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> info;
            if (info == '.') map[i][j] = 1;
            else if (info == 'X') map[i][j] = 0;
        }
    }

    int rowcnt = 0, colcnt = 0;
    for (int i = 1; i <= n; ++i) {
        int tmp = 0;
        for (int j = 1; j <= n; ++j) {
            if (map[i][j]) {
                tmp++;
                if (tmp == 2) {
                    rowcnt++;
                }
            } else {
                tmp = 0;
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        int tmp = 0;
        for (int j = 1; j <= n; ++j) {
            if (map[j][i]) {
                tmp++;
                if (tmp == 2) {
                    colcnt++;
                }
            } else {
                tmp = 0;
            }
        }
    }

    cout << rowcnt << ' ' << colcnt << endl;
    return 0;
}