#include <iostream>
using namespace std;

int cnt;
bool nums[42];

int main()
{
    for (int i = 1; i <= 10; ++i) {
        int a; cin >> a;
        nums[a % 42] = true;
    }

    for (int i = 0; i < 42; ++i) {
        if (nums[i]) cnt++;
    }
    cout << cnt << '\n';
    return 0;
}