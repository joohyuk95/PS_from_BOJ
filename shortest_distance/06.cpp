#include <iostream>
#include <queue>
using namespace std;
int dx[2] = {-1, +1};

int main()
{
    ios_base::sync_with_stdio(false);
    int n, k, now, next;
    cin >> n >> k;
    vector<int> time(100001, -1);
    queue<int> Q;
    priority_queue<int> pq;
    time[n] = 0;
    Q.push(n);

    while (!Q.empty()) {
        now = Q.front();
        Q.pop();
        for (int i = 0; i < 3; ++i) {
            if (i == 2) {
                next = 2 * now;
                if (next > 100000) continue;
                if (next == k) pq.push(time[now]); 
                else if (time[next] < 0) {
                    time[next] = time[now];
                    Q.push(next);
                }
            }
            else {
                next = now + dx[i];
                if (next < 0 || next > 100000) continue;
                if (next == k) pq.push(time[now] + 1);
                else if (time[next] < 0) {
                    time[next] = time[now] + 1;
                    Q.push(next);
                }
            }
        }
    }
    cout << pq.top() << endl;
    return 0;
}