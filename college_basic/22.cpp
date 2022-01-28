#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int k;
int arr[10];
char map[10];
bool visit[10];

vector<string> ans;
vector<char> v;

bool check(int idx, char c)
{
    if (c == '<') {
        if (v[idx] - '0' < v[idx + 1] - '0') return true;
        else return false;
    } else if (c == '>') {
        if (v[idx] - '0' > v[idx + 1] - '0') return true;
        else return false;
    }
}

bool calculate()
{
    for (int i = 0; i < k; ++i) {
        if (check(i, map[i]) == false) return false;
    }
    return true;
}

void DFS(int cnt)
{
    if (cnt == k + 1) {
        if (calculate() == true) {
            string tmp = "";
            for (int i = 0; i < v.size(); ++i) {
                tmp = tmp + v[i];
            }
            ans.push_back(tmp);
        }
        return;
    }
    for (int i = 0; i < 10; ++i) {
        if (visit[i] == true) continue;
        visit[i] = true;
        v.push_back(arr[i] + '0');
        DFS(cnt + 1);
        v.pop_back();
        visit[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> k;
    for (int i = 0; i < k; ++i) {
        char a; cin >> a;
        map[i] = a;
    }
    for (int i = 0; i < 10; ++i) {
        arr[i] = i;
    }

    DFS(0);
    sort(ans.begin(), ans.end());
    cout << ans.at(ans.size() - 1) << endl;
    cout << ans.at(0) << endl;
    return 0;
}