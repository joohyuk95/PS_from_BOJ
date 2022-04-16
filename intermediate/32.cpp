#include <iostream>
using namespace std;

int n, cnt;
bool prime[1001];

int main()
{
    cin >> n;

    for (int i = 2; i <= 1000; ++i) prime[i] = true;
    
    for (int i = 2; i*i <= 1000; ++i) {
        if (prime[i]) {
            for (int j = i*i; j <= 1000; j += i) {
                prime[j] = false;
            }
        }
    }

    int num = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> num;
        if (prime[num]) cnt++;
    }

    cout << cnt << '\n';
    return 0;
}