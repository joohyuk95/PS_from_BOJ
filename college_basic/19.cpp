#include <iostream>
#include <algorithm>
using namespace std;

int sum;
int height[9];

int main()
{
    for (int i = 0; i < 9; ++i) {
        cin >> height[i];
        sum += height[i];
    }

    sort(height, height + 9);
    for (int i = 0; i < 9; ++i) {
        for (int j = i + 1; j < 9; ++j) {
            if ((sum - (height[i] + height[j])) == 100) {
                for (int k = 0; k < 9; ++k) {
                    if (k == i || k == j) continue;
                    cout << height[k] << '\n';
                }
                exit(0);
            }
        }
    }

    return 0;
}