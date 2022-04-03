#include <iostream>
using namespace std;

int n, sum, max_score;
int score[1001];

int main()
{
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> score[i];
        sum += score[i];
        if (score[i] > max_score) max_score = score[i];
    }

    double res = (1.0)*sum/max_score*100/n;
    cout << res << '\n';
    return 0;
}