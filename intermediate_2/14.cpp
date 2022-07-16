#include <iostream>
using namespace std;

int c;
int scores[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout.precision(3);
    cout << fixed;

    cin >> c;
    for (int i = 1; i <= c; ++i) {
        int num; cin >> num;
        
        int sum = 0;
        for (int j = 1; j <= num; ++j) {
            cin >> scores[j];
            sum += scores[j];
        }
        int avg = sum / num;
        int cnt = 0;
        for (int j = 1; j <= num; ++j) {
            if (scores[j] > avg) cnt++;
        }

        double res = (1.0) * cnt / num * 100;
        cout << res << '%' << '\n';
    }
    return 0;
}