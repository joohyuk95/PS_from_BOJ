#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, begin, end;
    vector<pair<int, int>> schedule;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> begin >> end;
        schedule.push_back({end, begin});
    }
    sort(schedule.begin(), schedule.end());

    int time = schedule[0].first;
    int cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (time <= schedule[i].second) {
            cnt++;
            time = schedule[i].first;
        }
    }
    cout << cnt;
    return 0;
}