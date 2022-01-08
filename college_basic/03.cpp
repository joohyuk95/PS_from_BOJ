#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int color[4];
int number[10];
vector<int> nums;

bool isContinuous = true;
bool threeColor, fiveColor;
int twoSame, threeSame, fourSame;
int value, res;
int twoVal[2];

void check_number()
{
    int j = 0;
    for (int i = 1; i <= 9; ++i) {
        if (number[i] == 4) {
            fourSame++;
            value = i;
        } else if (number[i] == 3) {
            threeSame++;
            value = i;
        } else if (number[i] == 2) {
            twoSame++;
            twoVal[j++] = i;
        }
    }
}

void check_color()
{
    for (int i = 0; i < 4; ++i) {
        if (color[i] == 5) {
            fiveColor = true;
            break;
        } else if (color[i] == 3) {
            threeColor = true;
            break;
        }
    }
}

void check_continuity()
{
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] - nums[i-1] != 1) {
            isContinuous = false;
            break;
        } 
    }
}

int main()
{
    for (int i = 0; i < 5; ++i) {
        char a; int b; cin >> a >> b;
        
        switch (a) {
            case 'B' : color[0]++; break;
            case 'G' : color[1]++; break;
            case 'R' : color[2]++; break;
            case 'Y' : color[3]++;    
        }

        number[b]++;

        nums.push_back(b);
    }
    sort(nums.begin(), nums.end());
    check_color();
    check_number();
    check_continuity();
    sort(twoVal, twoVal + 2);

    if (fiveColor && isContinuous) {
        res = 900 + nums[4];
    } else if (fourSame) {
        res = 800 + value;
    } else if (threeSame && twoSame) {
        res = 700 + value * 10 + twoVal[1];
    } else if (fiveColor) {
        res = 600 + nums[4];
    } else if (isContinuous) {
        res = 500 + nums[4];
    } else if (threeSame) {
        res = 400 + value;
    } else if (twoSame == 2) {
        res = 300 + twoVal[1] * 10 + twoVal[0];
    } else if (twoSame) {
        res = 200 + twoVal[1];
    } else {
        res = 100 + nums[4];
    }

    cout << res << endl;
    return 0;
}