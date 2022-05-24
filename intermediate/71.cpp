#include <iostream>
using namespace std;

int n; 
long long f[91];

long long Fibonacci(int n)
{
    if (n == 0 || n == 1) return n;
    if (f[n]) return f[n];
    else return f[n] = Fibonacci(n-1) + Fibonacci(n-2);
}

int main()
{
    cin >> n;
    f[1] = 1;

    cout << Fibonacci(n) << '\n';
    return 0;
}