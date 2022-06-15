#include <iostream>
#include <algorithm>
using namespace std;

int nums[4];

int main()
{
    for (int i = 0; i < 4; ++i) cin >> nums[i];
    sort(nums, nums+4);

    cout << nums[0]*nums[2] << '\n';
    return 0;
}