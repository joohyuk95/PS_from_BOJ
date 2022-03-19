#include <iostream>
using namespace std;

int cnt;
char chess[8][8];

int main()
{
    ios_base::sync_with_stdio(false);
    for (int i = 0; i <= 7; ++i) {
        for (int j = 0 ; j <= 7; ++j) {
            cin >> chess[i][j];
            if (i % 2 == j % 2 && chess[i][j] == 'F') cnt++;
        }
    }

    cout << cnt << '\n';
    return 0;
}