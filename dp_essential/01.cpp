#include <iostream>
using namespace std;

int n, nums[50] = {0, 1};

int Fibonacci(int n)
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (nums[n]) return nums[n];

    return nums[n] = Fibonacci(n - 2) + Fibonacci(n - 1);
}

int main()
{
    cin >> n;
    cout << Fibonacci(n) << '\n';

    return 0;
}