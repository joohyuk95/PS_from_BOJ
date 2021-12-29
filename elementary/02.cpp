#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 101

int map[MAX];
bool visit[MAX];
vector<int> res;

void DFS(int start, int cur)
{
    if (visit[cur]) {
        if (start == cur) {
            res.push_back(start);
            return;
        }
    } else {
        visit[cur] = true;
        DFS(start, map[cur]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> map[i];
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) visit[j] = false;
        DFS(i, i);
    }

    sort(res.begin(), res.end());
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << endl;
    }
    return 0;
}