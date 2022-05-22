#include <iostream>
using namespace std;

int n, m;
int mat[101][101];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> mat[i][j];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int add; cin >> add;
            mat[i][j] += add;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << mat[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}