// 1. 간선 두 개 이상 가능
// 2. 맥날, 스벅 같이 있을 수 있음 (집은 같이 있을 수 없음)
// 3. 집은 무조건 있음
// 4. 원하는 집이 존재하지 않으면 -1 출력

/*
꽤나 복잡하니까 알고리즘을 차근차근 적어보자.
일단 1번 조건은 처리 안 해주고 해보겠음 (될 것 같기도 함)
2번 조건은 다익스트라 중복 시간 단축 해줄 수 있을 것 같음 오류는 안 생길듯?
맥날, 스벅 있는 곳에는 집이 없으니까 조건에서 빼야됨, 근데 그냥 마지막에 빼줘도 될듯?
dist 갱신 어떻게 해줄건지랑 x, y 만족하는거 어떻게 더해줄지랑, dist에 거리랑 정점도 pair로 넣어줄지 생각
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 100000000
using namespace std;

vector<pair<int, int> > map[10001];
vector<int> dist_m(10001);
vector<int> dist_s(10001);

class Info {
public:
    int node, cost;

    bool operator<(const Info &rhs) const {
        return this->cost > rhs.cost;
    }
};
priority_queue<Info> pq;
priority_queue<Info> res;

bool isHouse(int vertex, vector<int> &mac, vector<int> &star) 
{
    for (int i = 0; i < mac.size(); ++i) {
        if (mac[i] == vertex) return false;
    }
    for (int i = 0; i < star.size(); ++i) {
        if (star[i] == vertex) return false;
    }
    return true;
}

void Dijkstra(int start, bool isMac)
{
    if (isMac) {
        fill(dist_m.begin(), dist_m.end(), INF);
        dist_m[start] = 0;
    } else {
        fill(dist_s.begin(), dist_s.end(), INF);
        dist_s[start] = 0;
    }
    pq.push({start, 0});

    while (!pq.empty()) {
        int node = pq.top().node;
        int cost = pq.top().cost;
        pq.pop();
        
        for (int i = 0; i < map[node].size(); ++i) {
            int nextNode = map[node][i].first;
            int nextCost = map[node][i].second;
            if (isMac) {
                if (dist_m[nextNode] > dist_m[node] + nextCost) {
                    dist_m[nextNode] = dist_m[node] + nextCost;
                    pq.push({nextNode, dist_m[nextNode]});
                }
            } else {
                if (dist_s[nextNode] > dist_s[node] + nextCost) {
                    dist_s[nextNode] = dist_s[node] + nextCost;
                    pq.push({nextNode, dist_s[nextNode]});
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int v, e;
    cin >> v >> e;
    for (int i = 1; i <= e; ++i) {
        int u, v, w; cin >> u >> v >> w;
        map[u].push_back(make_pair(v, w));
        map[v].push_back(make_pair(u, w));
    }
    
    int m, x, s, y;
    int small = (x < y) ? x : y;
    cin >> m >> x; vector<int> mac(m+1);
    for (int i = 1; i <= m; ++i) cin >> mac[i];
    
    cin >> s >> y; vector<int> star(s+1);
    for (int i = 1; i <= s; ++i) cin >> star[i];

    for (int i = 1; i <= m; ++i) {
        Dijkstra(mac[i], true);
        for (int j = 1; j <= s; ++j) {
            if (mac[i] == star[j]) {
                for (int k = 1; i <= v; ++k) {
                    if (dist_m[k] <= small) {
                        res.push({2 * dist_m[k]});
                    }
                }
            }
            else {
                Dijkstra(star[j], false);
                for (int k = 1; k <= v; ++k) {
                    if (dist_m[k] <= x && dist_s[k] <= y) {
                        res.push({k, dist_m[k] + dist_s[k]});
                    }
                }
            }
        }
    }

    while (true) {
        if (res.empty()) {
            cout << -1 << endl;
            break;
        }
        int vertex = res.top().node;
        if (isHouse(vertex, mac, star)) {
            cout << res.top().cost << endl;
            break;
        } else {
            res.pop();
        }
    }

    return 0;
}