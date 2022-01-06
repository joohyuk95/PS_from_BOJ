#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define boundary 2000000

bool isPalindrome(int num)
{
    string s = to_string(num);
    int l = 0;
    int r = s.length() - 1;
    while (l <= r) {
        if (s[l] != s[r]) return false;
        ++l;
        --r;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<bool> isPrime(boundary + 1, true);
    isPrime[1] = false;
    for (int i = 2; i * i <= boundary; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= boundary; j += i) {
                isPrime[j] = false;
            }
        }
    }

    int i = n;
    while (true) {
        if (isPrime[i] && isPalindrome(i)) {
            cout << i << endl;
            break;
        }
        ++i;
    }
    return 0;
}