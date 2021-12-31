#include <iostream>
using namespace std;

#define MAX 11
bool map[MAX][MAX], draw[MAX][MAX];

bool isValid(int row, int col)
{
    return 0 <= row && row < MAX && 0 <= col && col < MAX;
}

bool check()
{
    for (int i = 1; i < MAX; ++i) {
        for (int j = 1; j < MAX; ++j) {
            if (map[i][j] != draw[i][j]) return false;
        }
    }
}

bool case1(int row, int col, int len)
{
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j <= i; ++j) {
            int nrow = i + row, ncol = j + col;
            if (!isValid(nrow, ncol)) return false;
            draw[nrow][ncol] = 1;
        }
    }
    return true;
}

bool case2(int row, int col, int len)
{
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j <= len - 1 - i; ++j) {
            int nrow = i + row, ncol = j + col;
            if (!isValid(nrow, ncol)) return false;
            draw[nrow][ncol] = 1;
        }
    }
    return true;
}

bool case3(int row, int col, int len)
{
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j >= -i; --j) {
            int nrow = i + row, ncol = j + col;
            if (!isValid(nrow, ncol)) return false;
            draw[nrow][ncol] = 1;
        }
    }
    return true;
}

bool case4(int row, int col, int len)
{
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j >= -(len - 1 - i); --j) {
            int nrow = i + row, ncol = j + col;
            if (!isValid(nrow, ncol)) return false;
            draw[nrow][ncol] = 1;
        }
    }
    return true;
}

bool case5(int row, int col, int len)
{
    return len & 1 && case1(row, col, len / 2) && case2(row + len / 2, col, len / 2 + 1);
}

bool case6(int row, int col, int len)
{
    return len & 1 && case4(row, col, len / 2) && case2(row, col + len / 2, len / 2 + 1);
}

bool case7(int row, int col, int len)
{
    return len & 1 && case3(row, col, len / 2) && case4(row + len / 2, col - len / 2, len / 2 + 1);
}

bool case8(int row, int col, int len)
{
    return len & 1 && case3(row, col, len / 2) && case1(row - len / 2, col + len / 2, len / 2 + 1);
}

int main()
{
    for (int i = 1; i < MAX; ++i) {
        for (int j = 1;  j < MAX; ++j) {
            cin >> map[i][j];
        }
    }

    for (int k = 0; k < 8; ++k) {
        for (int i = 1; i < MAX; ++i) {
            for (int j = 1; j < MAX; ++j) {
                for (int l = 2; l < MAX; ++l) {

                }
            }
        }
    }

    return 0;
}