#include <iostream>
#include <vector>
#define INF 2147000000
using namespace std;

class Edge {
public:
    int s, e, val;

    Edge (int a, int b, int c) {
        this->s = a;
        this->e = b;
        this->val = c;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m, a, b, c;
    vector<Edge> Ed;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a >> b >> c;
        Ed.push_back(Edge(a, b, c));
    }
    vector<long> dist(n+1, INF);
    dist[1] = 0;
    for (int i = 1; i <= n-1; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dist[j] != INF) {
                for (int k = 0; k < m; ++k) {
                    if (Ed[k].s == j && dist[Ed[k].e] > dist[Ed[k].s] + Ed[k].val)
                        dist[Ed[k].e] = dist[Ed[k].s] + Ed[k].val;
                }
            }
        }
    }
    
    bool flag = false;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] != INF) {
            for (int k = 0; k <= m; ++k) {
                if (Ed[k].s == i && dist[Ed[k].e] > dist[Ed[k].s] + Ed[k].val)
                    flag = true;
            }
        }
    }
    if (flag) cout << -1 << endl;
    else {
        for (int i = 2; i <= n; ++i) {
            if (dist[i] == INF) cout << -1 << endl;
            else cout << dist[i] << endl;
        }
    }
    return 0;
}