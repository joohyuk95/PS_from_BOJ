#include <iostream>
#define MAX 246913
using namespace std;

bool isPrime[MAX];

int main()
{
    for (int i = 2; i < MAX; ++i) isPrime[i] = true;
    
    for (int i = 1; i*i < MAX; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j < MAX; j += i) {
                isPrime[j] = false;
            }
        }
    }

    while (true) {
        int num; cin >> num;
        if (num == 0) break;

        int cnt = 0;
        for (int i = num+1; i <= 2*num; ++i) {
            if (isPrime[i]) cnt++;
        }
        cout << cnt << '\n';
    }

    return 0;
}