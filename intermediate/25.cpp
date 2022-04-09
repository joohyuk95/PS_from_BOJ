#include <iostream>
#include <vector>
using namespace std;

int n1, d1;
int n2, d2;

int GCD(int numer, int denom)
{
    int rem = numer % denom;
    if (rem) return GCD(denom, rem);
    else return denom;
}

int main()
{
    cin >> n1 >> d1 >> n2 >> d2;
    int n = n1*d2 + n2*d1;
    int d = d1*d2;

    int gcd = GCD(n, d);

    cout << n / gcd << ' ' << d / gcd << '\n';
    return 0;
}