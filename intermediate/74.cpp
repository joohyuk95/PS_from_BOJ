#include <iostream>
using namespace std;

int t;
int nums[15];

int main()
{
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int k, n; cin >> k >> n;
        for (int j = 1; j <= n; ++j) nums[j] = j;
        
        int sum = 0;
        for (int j = 1; j < k; ++j) {
            int cnt = 0;
            for (int p = 1; p <= n; ++p) {
                cnt += nums[p];
                nums[p] = cnt;
            }
        }
        for (int j = 1; j <= n; ++j) sum += nums[j];
        cout << sum << '\n';
    }
    return 0;
}