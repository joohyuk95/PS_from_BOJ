#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, cnt;
vector<int> map[51];
vector<pair<int, int> > res(51);
priority_queue<int, vector<int>, greater<int>> pq;

int BFS(int s)
{
    queue<int> Q;
    vector<int> dist(n+1);
    vector<int> ch(n+1);
    Q.push(s);
    ch[s] = 1;
    while (!Q.empty()) {
        int tmp = Q.front(); 
        Q.pop();
        for (int i = 0; i < map[tmp].size(); ++i) {
            if (!ch[map[tmp][i]]) {
                ch[map[tmp][i]] = 1;
                Q.push(map[tmp][i]);
                dist[map[tmp][i]] = dist[tmp] + 1;
            }
        }
    }

    int max = 0;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] > max) max = dist[i];
    }
    return max;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    while (true) {
        int a, b;
        cin >> a >> b;
        if (a == -1 && b == -1) break;
        map[a].push_back(b);
        map[b].push_back(a);
    }

    int min = 50;
    for (int i = 1; i <= n; ++i) {
        res[i] = make_pair(i, BFS(i));
        if (res[i].second < min) {
            cnt = 1;
            min = res[i].second;
        } else if (res[i].second == min) {
            cnt++;
        }
    }
    cout << min << ' ' << cnt << endl;
    for (int i = 1; i <= n; ++i) {
        if (res[i].second == min) pq.push(res[i].first);
    }
    while (!pq.empty()) {
        cout << pq.top() << ' ';
        pq.pop();
    }
    cout << endl;
    return 0;
}