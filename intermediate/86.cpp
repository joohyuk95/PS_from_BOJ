#include <iostream>
using namespace std;

int nums[8];
int check;

int main()
{
    for (int i = 0; i < 8; ++i) cin >> nums[i];
    switch (nums[0]) {
    case 1:
        check = 0;
        break;
    case 8:
        check = 1;
        break;
    default:
        check = 2;
        break;
    }
    
    switch (check) {
    case 0:
        for (int i = 1; i < 8; ++i) {
            if (nums[i] == nums[i-1]+1) continue;
            else {
                cout << "mixed" << '\n';
                return 0;
            }
        }
        cout << "ascending" << '\n';
        break;
    case 1:
        for (int i = 1; i < 8; ++i) {
            if (nums[i] == nums[i-1]-1) continue;
            else {
                cout << "mixed" << '\n';
                return 0;
            }
        }
        cout << "descending" << '\n';
        break;
    case 2:
        cout << "mixed" << '\n';
        break;
    }

    return 0;
}