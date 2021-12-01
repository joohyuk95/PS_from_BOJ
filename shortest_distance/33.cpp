#include <iostream>
#include <queue>
#include <vector>
#define INF 1250
using namespace std;
int n;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

class Info {
public:
    int x, y, cost;

    bool operator<(const Info &rhs) const {
        return this->cost > rhs.cost;
    }
};
priority_queue<Info> pq;
queue<int> Q;

int main()
{
    ios_base::sync_with_stdio(false);
    while (true) {
        cin >> n;
        if (n == 0) break;
        vector<vector<int> > map(n, vector<int> (n));
        vector<vector<int> > dist(n, vector<int> (n, INF));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> map[i][j];
            }
        }
        dist[0][0] = map[0][0];
        pq.push({0, 0, dist[0][0]});

        while (!pq.empty()) {
            int x = pq.top().x;
            int y = pq.top().y;
            pq.pop();
            if (dist[x][y] < map[x][y]) continue;
            
            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx > n-1 || nx < 0 || ny > n-1 || ny < 0) continue;
                if (dist[nx][ny] > dist[x][y] + map[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + map[nx][ny];
                    pq.push({nx, ny, dist[nx][ny]});
                }
            }
        }
        Q.push(dist[n-1][n-1]);
    }
    
    int i = 1;
    while (!Q.empty()) {
        cout << "Problem " << i << ": " << Q.front() << endl;
        Q.pop();
        i++;
    }
    return 0;
}