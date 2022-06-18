#include <iostream>
using namespace std;

int n, ans;
char box[51][51];

void swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void check()
{
    for (int i = 1; i <= n; ++i) {
        int cnt = 1;
        char ch = box[i][1];
        for (int j = 2; j <= n; ++j) {
            if (box[i][j] == ch) cnt++;
            else cnt = 1;
            ch = box[i][j];
            if (cnt > ans) ans = cnt;
        }
    }

    for (int j = 1; j <= n; ++j) {
        int cnt = 1;
        char ch = box[1][j];
        for (int i = 2; i <= n; ++i) {
            if (box[i][j] == ch) cnt++;
            else cnt = 1;
            ch = box[i][j];
            if (cnt > ans) ans = cnt;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> box[i][j];
        }
    }
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < n; ++j) {
            if (box[i][j] != box[i][j+1]) {
                swap(box[i][j], box[i][j+1]);
                check();
                if (ans == n) {
                    cout << ans << '\n';
                    return 0;
                }
                swap(box[i][j], box[i][j+1]);
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (box[i][j] != box[i][j+1]) {
                swap(box[i][j], box[i+1][j]);
                check();
                if (ans == n) {
                    cout << ans << '\n';
                    return 0;
                }
                swap(box[i][j], box[i+1][j]);
            }
        }
    }

    cout << ans << '\n';
    return 0;
}