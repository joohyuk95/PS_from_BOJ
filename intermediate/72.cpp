#include <iostream>
#include <algorithm>
using namespace std;

int n;
int nums[1001];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
    }
    sort(nums+1, nums+n+1);
    for (int i = 1; i <= n; ++i) cout << nums[i] << '\n';

    return 0;
}