#include <iostream>
using namespace std;

int t;
int g_score[6] = {1, 2, 3, 3, 4, 10};
int s_score[7] = {1, 2, 2, 2, 3, 5, 10};

int main()
{
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int sumx = 0;
        for (int j = 0; j < 6; ++j) {
            int num; cin >> num;
            sumx += g_score[j]*num;
        }
        int sumy = 0;
        for (int j = 0; j < 7; ++j) {
            int num; cin >> num;
            sumy += s_score[j]*num;
        }

        cout << "Battle " << i << ": ";
        if (sumx > sumy) cout << "Good triumphs over Evil" << '\n';
        else if (sumx < sumy) cout << "Evil eradicates all trace of Good" << '\n';
        else cout << "No victor on this battle field" << '\n';
    }

    return 0;
}