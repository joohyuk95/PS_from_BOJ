#include <iostream>
using namespace std;

int n, cnt;
int score[101];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> score[i];

    for (int i = n; i > 1; --i) {
        while (score[i] <= score[i-1]) {
            score[i-1]--;
            cnt++;
        }
    }

    cout << cnt << '\n';
    return 0;
}