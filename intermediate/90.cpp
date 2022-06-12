#include <iostream>
using namespace std;

int nums[5];

void swap(int *pa, int *pb)
{
    int tmp = *pa;
    *pa = *pb;
    *pb = tmp;
}

bool arrEqual(int arr[], int count)
{
    bool flag = true;
    for (int i = 0; i < count; ++i) {
        if (arr[i] != i+1) {
            flag = false;
            break;
        }
    }
    return flag;
}

int main()
{
    for (int i = 0; i < 5; ++i) cin >> nums[i];

    while (true) {
        for (int i = 0; i < 4; ++i) {
            if (nums[i] > nums[i+1]) {
                swap(&nums[i], &nums[i+1]);
                for (int j = 0; j < 5; ++j) cout << nums[j] << ' ';
                cout << endl;
            }
        }
        if (arrEqual(nums, sizeof(nums)/sizeof(int))) break;
    }

    return 0;
}