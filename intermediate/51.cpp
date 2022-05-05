#include <iostream>
using namespace std;

int n;
int total;
int score = 1;
bool seq;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        bool ans; cin >> ans;
        if (ans) {
            if (seq) total += ++score;
            else {
                total += score;
                seq = true;
            }
        } else {
            score = 1;
            seq = false;
        }
    }

    cout << total << '\n';
    return 0;
}