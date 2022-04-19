#include <iostream>
using namespace std;

int str2num(string s)
{
    int sum = 0;
    for (int i = 0; i < s.size(); ++i) {
        if ('A' <= s[i] && s[i] <= 'Z') {
            sum += int(s[i]) - 65 + 27;
        } else {
            sum += int(s[i]) - 96;
        }
    }

    return sum;
}

bool isPrime(int n)
{
    bool flag = true;
    for (int i = 2; i < n; ++i) {
        if (n % i == 0) flag = false;
    }
    
    return flag;
}

int main()
{
    string str;
    cin >> str;

    int num = str2num(str);

    if (isPrime(num)) cout << "It is a prime word." << '\n';
    else cout << "It is not a prime word." << '\n';

    return 0;
}