#include <iostream>
#include <algorithm>
using namespace std;

int list[17];

int main()
{
    while (true) {
        cin >> list[1];
        if (list[1] == -1) break;

        int i = 2;
        for (i = 2; i <= 16; ++i) {
            cin >> list[i];
            if (list[i] == 0) break;
        }

        int cnt = 0;
        sort(list + 1, list + i);

        for (int j = 1; j < i-1; ++j) {
            for (int k = j+1; k < i; ++k) {
                if (list[k] == 2*list[j]) {
                    cnt++;
                    break;
                }
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}