#include <iostream>
using namespace std;

int t;

int main()
{
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        string a, b;
        cin >> a >> b;

        int n = a.size();

        long A = stol(a, 0, 2);
        long B = stol(b, 0, 2);

        long X = A ^ B;

        long cnt = 0;

        for (int i = 0; i < n; ++i) {
            cnt += (X>>i & 1);
        }
        cout << "Hamming distance is " << cnt << '.' << '\n';
    }

    return 0;
}