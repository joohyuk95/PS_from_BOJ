#include <iostream>
using namespace std;

int n, k, cnt;
bool nums[1001];

int main()
{
    cin >> n >> k;
    
    for (int i = 1; i <= n; ++i) nums[i] = true;
    
    for (int i = 2; i <= n; ++i) {
        if (nums[i]) {
            for (int j = i; j <= n; j = j + i) {
                if (nums[j]) {
                    nums[j] = false;
                    cnt++;
                    if (cnt == k) {
                        cout << j << '\n';
                        return 0;
                    }        
                }
            }
        }
    }

    return 0;
}