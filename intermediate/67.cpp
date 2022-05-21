#include <iostream>
using namespace std;

int t;
int q = 25, d = 10, n = 5, p = 1;

int main()
{
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int c; cin >> c;
        int q_cnt = 0, d_cnt = 0, n_cnt = 0, p_cnt = 0;
        while (c >= q) {c -= q; q_cnt++;}
        while (c >= d) {c -= d; d_cnt++;}
        while (c >= n) {c -= n; n_cnt++;}
        while (c >= p) {c -= p; p_cnt++;}
        cout << q_cnt << ' ' << d_cnt << ' ' << n_cnt << ' ' << p_cnt << '\n';
    }

    return 0;
}