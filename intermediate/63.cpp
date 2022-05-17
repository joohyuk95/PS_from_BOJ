#include <iostream>
#include <algorithm>
using namespace std;

int t;
int nums[10];

int main()
{
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        for (int j = 0; j < 10; ++j) {
            cin >> nums[j];
        }
        sort(nums, nums + 10);
        cout << nums[7] << '\n';
    }

    return 0;
}