#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m, a, b, c, dist;
    cin >> n >> m;
    vector<vector<int> > straight(n+1, vector<int> (n+1));
    vector<vector<int> > via(n+1, vector<int> (n+1));
    queue<tuple<int, int, int> > Q;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> straight[i][j];
            via[i][j] = straight[i][j];
        }
    }
    for (int i = 1; i <= m; ++i) {
        cin >> a >> b >> c;
        Q.push(make_tuple(a, b, c));
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                via[i][j] = min(via[i][j], via[i][k] + via[k][j]);
            }
        }
    }
    
    while(!Q.empty()) {
        int s = get<0>(Q.front());
        int e = get<1>(Q.front());
        int time = get<2>(Q.front());
        Q.pop();
        
        if (via[s][e] < straight[s][e]) dist = via[s][e];
        else dist = straight[s][e];
        
        if (dist <= time) cout << "Enjoy other party" << endl;
        else  cout << "Stay here" << endl;
    }

    return 0;
}