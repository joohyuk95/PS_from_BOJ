#include <iostream>
using namespace std;

double nums[4];
double ans[4];

int main()
{
    for (int i = 0; i < 4; ++i) cin >> nums[i];
    
    ans[0] = nums[0] / nums[2] + nums[1] / nums[3];
    ans[1] = nums[2] / nums[3] + nums[0] / nums[1];
    ans[2] = nums[3] / nums[1] + nums[2] / nums[0];
    ans[3] = nums[1] / nums[0] + nums[3] / nums[2];
    
    int idx = 0;
    double max = 0;
    for (int i = 0; i < 4; ++i) {
        if (ans[i] > max) {
            max = ans[i];
            idx = i; 
        }
    }

    cout << idx << '\n';
    return 0;
}