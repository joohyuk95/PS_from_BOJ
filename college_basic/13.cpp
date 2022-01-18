#include <iostream>
#include <queue>
#define MAX 100000
#define MIN 0
using namespace std;

int visit[MAX];
int dx[3] = {1, -1, 2};

int main()
{
    int n, k;
    cin >> n >> k;

    queue<int> Q;
    Q.push(n);
    visit[n] = true;

    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        if (cur == k) break;

        for (int i = 0; i < 3; ++i) {
            int next;
            if (i == 2) next = cur * dx[i];
            else next = cur + dx[i];
            
            if (MIN <= next && next <= MAX && !visit[next]) {
                visit[next] = visit[cur] + 1;
                Q.push(next);
            }
        }
    }
    cout << visit[k] - 1 << endl;
    return 0;
}