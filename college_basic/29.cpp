#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a; cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    int sum = 0;
    int total = 0;
    for (int i = 0; i < v.size(); ++i) {
        sum += v[i];
        total += sum;
    }
    cout << total << '\n';
    return 0;
}