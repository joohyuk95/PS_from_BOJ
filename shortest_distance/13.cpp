#include <iostream>
#include <vector>
using namespace std;

#define INF 5000000

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

bool bellmanFord(int n, int m, int w)
{
    int a, b, c;
    Ed.clear();
    for (int i = 1; i <= n; ++i) dist[i] = INF;
    for (int i = 1; i <= m; ++i) {
        cin >> a >> b >> c;
        Ed.push_back(Edge(a, b, c));
        Ed.push_back(Edge(b, a, c));
    }
    for (int i = 1; i <= w; ++i) {
        cin >> a >> b >> c;
        Ed.push_back(Edge(a, b, -c));
    }

    dist[1] = 0;
    for (int i = 1; i <= n-1; ++i) {
        for (int j = 0; j < Ed.size(); ++j) {
            int s = Ed[j].s;
            int e = Ed[j].e;
            int t = Ed[j].t;
            
            if (dist[s] == INF) continue;
            if (dist[e] > dist[s] + t) dist[e] = dist[s] + t;
        }
    }
    for (int i = 0; i < Ed.size(); ++i) {
        int s = Ed[i].s;
        int e = Ed[i].e;
        int t = Ed[i].t;
        
        if (dist[s] == INF) continue;
        if (dist[e] > dist[s] + t) {
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int tc;
    vector<bool> ncycle(5);
    cin >> tc;
    for (int i = 0; i < tc; ++i) {
        int a, b, c; cin >> a >> b >> c;
        ncycle[i] = bellmanFord(a, b, c);
    }
    for (int i = 0; i < tc; ++i) {
        if (ncycle[i]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}