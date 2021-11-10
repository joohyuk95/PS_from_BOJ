// n, m 도시
// 모든 도시는 연결되어 있음
// n과 플로이드 와샬 결과가 주어짐
// 원래 도로가 최솟값 일때 가중치 총합 구하기
#include <iostream>
#include <vector>
using namespace std;
vector<int> res[21];

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int> > map(n+1, vector<int> (n+1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> map[i][j];
        }
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (map[i][j] > map[i][k] + map[k][j]) {
                    cout << -1 << endl;
                    exit(0);
                }
                else if (map[i][j] == map[i][k] + map[k][j]) {
                    res[i].push_back(k);
                    res[k].push_back(j);
                }
            }
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= res[i].size(); ++j) {
            cnt += map[i][res[i][j]]; 
        }
    }
    cout << cnt << endl;
    return 0;
}