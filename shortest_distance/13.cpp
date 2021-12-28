#include <iostream>
#include <vector>
using namespace std;

#define INF 5000000

int tc, n, m, w;
bool ncycle;

int dist[501];

class Edge {
public:
    int s, e, t;

    Edge(int a, int b, int c) {
        this->s = a;
        this->e = b;
        this->t = c;
    }
};
vector<Edge> Ed;

bool bellmanFord()
{
    dist[1] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < Ed.size(); ++j) {
            int s = Ed[j].s;
            int e = Ed[j].e;
            int t = Ed[j].t;
            
            if (dist[e] > dist[s] + t) {
                dist[e] = dist[s] + t;
                if (i == n) return true;
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> tc;
    for (int k = 1; k <= tc; ++k) {
        Ed.clear();
        for (int i = 1; i <= n; ++i) dist[i] = INF;

        cin >> n >> m >> w;
        for (int i = 1; i <= m; ++i) {
            int a, b, c; cin >> a >> b >> c;
            Ed.push_back(Edge(a, b, c));
            Ed.push_back(Edge(b, a, c));
        }
        for (int i = 1; i <= w; ++i) {
            int a, b, c; cin >> a >> b >> c;
            Ed.push_back(Edge(a, b, -c));
        }
        
        ncycle = bellmanFord();
        if (ncycle) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}