#include <iostream>
#include <vector>
using namespace std;

int n;
bool visit[9];

void permutation (int cnt, vector<int> result)
{
    if (cnt == n + 1) {
        for (int i = 1; i <= n; ++i) cout << result[i] << ' ';
        cout << '\n';
        return;
    } else {
        for (int i = 1; i <= n; ++i) {
            if (visit[i]) continue;    
            visit[i] = true;
            result[cnt] = i;
            permutation(cnt + 1, result);
            visit[i] = false;
        }
    }
}

int main()
{
    cin >> n;

    vector<int> result(n+1);
    permutation(1, result);

    return 0;
}