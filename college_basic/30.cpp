#include <iostream>
#include <algorithm>
using namespace std;

int n, sum;
int A[50], B[50];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> A[i];
    for (int i = 0; i < n; ++i) cin >> B[i];

    sort(A, A + n, greater<>());
    sort(B, B + n);
    
    for (int i = 0; i < n; ++i) {
       sum += A[i] * B[i]; 
    }
    cout << sum << '\n';
    return 0;
}