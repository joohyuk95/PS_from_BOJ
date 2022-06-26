#include <iostream>
#include <algorithm>
using namespace std;

int n;
int nums[10001];
bool flag;

int main()
{
    cin >> n;
    if (n == 1) {
        cout << -1 << '\n';
        return 0;
    }
    for (int i = 1; i <= n; ++i) cin >> nums[i];

    int i;
    for (i = n-1; i >= 1; --i) {
        if (nums[i] < nums[i + 1]) {
            if (i == 1) flag = true;
            continue;
        } else break;
    }
    if (flag) {
        cout << -1 << '\n';
        return 0;
    }

    int ref = nums[i];
    int maxi = 0;
    int idx;
    for (int j = n; j > i; --j) {
        if (nums[j] < ref && nums[j] > maxi) {
            maxi = nums[j];
            idx = j;
        }
    }
    
    nums[i] = nums[idx];
    nums[idx] = ref;
    sort(nums+i+1, nums + n+1, greater<>());
    
    for (int i = 1; i <= n; ++i) cout << nums[i] << ' ';
    return 0;
}