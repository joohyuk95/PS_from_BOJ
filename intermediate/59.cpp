#include <iostream>
using namespace std;

int max_idx, max_val, sum;
int cnt[101];
int nums[10];

int main()
{
    for (int i = 0; i < 10; ++i) {
        cin >> nums[i];
        sum += nums[i];
        cnt[nums[i]/10]++;
    }

    for (int i = 1; i <= 100; ++i) {
        if (cnt[i] > max_val) {
            max_val = cnt[i];
            max_idx = i;
        }
    }

    cout << sum / 10 << '\n' << max_idx*10 << '\n';
    return 0;
}