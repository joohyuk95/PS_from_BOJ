#include <iostream>
#define MAX 1299710
using namespace std;

int t;
bool prime[MAX];

int main()
{
    cin >> t;

    for (int i = 2; i < MAX; ++i) prime[i] = true;
    for (int i = 2; i * i < MAX; ++i) {
        if (prime[i]) {
            for (int j = i * i; j < MAX; j += i) {
                prime[j] = false;
            }
        }
    }

    for (int i = 1; i <= t; ++i) {
        int num; cin >> num;
        if (prime[num]) cout << 0 << '\n';
        else {
            int lower = num-1;
            while (true) {
                if (prime[lower]) break;
                lower--;
            }

            int upper = num+1;
            while (true) {
                if (prime[upper]) break;
                upper++;
            }
            cout << upper - lower << '\n';
        }
    }

    return 0;
}