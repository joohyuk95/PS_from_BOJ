// 음의 가중치는 방향
// 무방향 가중치 그래프
// 방향성 제고, 출력 순서 제고
#include <iostream>
#include <vector>
#define INF 2147000000
using namespace std;

class Edge {
public:
    int s, e, t;

    Edge(int a, int b, int c) {
        this->s = a;
        this->e = b;
        this->t = c;
    }
};

bool bellmanFord(int n, int m, int w)
{   
    int a, b, c;
    vector<Edge> Ed;
    vector<long> dist(n+1, INF);
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
        for (int j = 1; j <= n; ++j) {
            if (dist[j] != INF) {
                for (int k = 0; k < m; ++k) {
                    if (Ed[k].s == j && dist[Ed[k].e] > dist[Ed[k].s] + Ed[k].t) {
                        dist[Ed[k].e] = dist[Ed[k].s] + Ed[k].t;
                    }
                }
            }
        }
    }
    
    bool flag = false;
    for (int i = 1; i <= n; ++i) {
        cout << i << ' ' << dist[i] << endl;
        if (dist[i] != INF) {
            for (int j = 0; j < m; ++j) {
                if (m == 2 && j == 2) cout << Ed[j].t << endl;
                if (Ed[j].s == i && dist[Ed[j].e] > dist[Ed[j].s] + Ed[j].t) {
                    flag = true;
                }
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int tc, a, b, c;
    vector<bool> ncycle(5);
    cin >> tc;
    for (int i = 0; i < tc; ++i) {
        cin >> a >> b >> c;
        ncycle[i] = bellmanFord(a, b, c);
    }
    for (int i = 0; i < 3; ++i) {
        cout << ncycle[i] << endl;
        //if (ncycle[i]) cout << "YES" << endl;
        //else cout << "NO" << endl;
    }
    return 0;
}