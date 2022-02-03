#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    map<string, int> ma;
    vector<string> vt;

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n+m; ++i) {
        string str;
        cin >> str;
        ma[str]++;
        if (ma[str] > 1) vt.push_back(str);
    }
    sort(vt.begin(), vt.end());

    return 0;
}