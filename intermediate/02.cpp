#include <iostream>
#include <algorithm>
using namespace std;

int n;
int divisor[51];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> divisor[i];
    sort(divisor, divisor + n + 1);
    
    cout << divisor[1] * divisor[n] << '\n';
    return 0;
}