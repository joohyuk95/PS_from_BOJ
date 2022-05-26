#include <iostream>
using namespace std;

int t;
bool nums[10];

int main()
{
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        string num; cin >> num;
        for (int j = 0; j < 10; ++j) nums[j] = false;
        for (int j = 0; j < num.size(); ++j) {
            nums[int(num[j])-48] = true;
        }

        int beauty = 0;
        for (int j = 0; j < 10; ++j) {
            if (nums[j]) beauty++;
        }
        cout << beauty << '\n';
    }
    
    return 0;
}