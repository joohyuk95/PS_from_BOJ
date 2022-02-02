#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int length, n;
    while (true) {
        if (cin >> length) {
            length *= 10000000;
            cin >> n;
            vector<int> block(n);
            for (int i = 0; i < n; ++i) {
                cin>> block[i];
            }
            sort(block.begin(), block.end());

            int l = 0, r = n - 1;
            while (l < r) {
                int sum = block[l] + block[r];
                if (sum == length) break;
                else if (sum < length) l++;
                else if (sum > length) r--;
            }
            if (l >= r) cout << "danger" << '\n';
            else {
                cout << "yes " << block[l] << ' ' << block[r] << '\n';
            }
        } else break;
    }

    return 0;
}