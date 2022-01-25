#include <iostream>
#include <vector>
using namespace std;

int n, ans;
int num[8];
bool check[8];
vector<int> v;

void calculate()
{
    int sum = 0;
    for (int i = 0; i < v.size() - 1; ++i) {
        sum += abs(v[i] - v[i+1]);
    }
    ans = max(ans, sum);
}

void DFS(int cnt)
{
    if (cnt == n) {
        calculate();
        return;
    }

    for (int i = 0; i < n; ++i) {
        if (check[i] == true) continue;
        check[i] = true;
        v.push_back(num[i]);
        DFS(cnt + 1);
        check[i] = false;
        v.pop_back();
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }
    DFS(0);
    cout << ans << endl;
    return 0;
}