#include <iostream>
using namespace std;

int n, max_val, idx;
int card[1001][5];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> card[i][j];
        }
    }

    for (int p = 1; p <= n; ++p) {
        for (int i = 0; i < 3; ++i) {
            for (int j = i+1; j < 5; ++j) {
                for (int k = j+1; k < 5; ++k) {
                    int sum = (card[p][i] + card[p][j] + card[p][k]) % 10;
                    if (sum >= max_val) {
                        max_val = sum;
                        idx = p;
                    }
                }
            }
        }
    }

    cout << idx << '\n';
    return 0;
}