#include <iostream>
#include <queue>
using namespace std;
int map[27][27];

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    char ch[5];
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> ch[j];
        }
        int p = ch[0] - 96;
        int q = ch[3] - 96;
        map[p][q] = 1;
    }
    for (int k = 1; k <= 26; ++k) {
        for (int i = 1; i <= 26; ++i) {
            for (int j = 1; j <= 26; ++j) {
                if (i == j || j == k || i == k) continue;
                if (map[i][k] && map[k][j]) map[i][j] = 1;
            }
        }
    }

    int m;
    cin >> m;
    queue<char> Q;
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> ch[j];
        }
        int p = ch[0] - 96;
        int q = ch[3] - 96;
        
        if (map[p][q]) Q.push('T');
        else Q.push('F');
    }
    while (!Q.empty()) {
        cout << Q.front() << endl;
        Q.pop();
    }
    return 0;
}