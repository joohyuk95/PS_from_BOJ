#include <iostream>
#include <algorithm>
using namespace std;

int lines[3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    while (true) {
        bool flag = true;
        for (int i = 0; i < 3; ++i) {
            cin >> lines[i];
            if (lines[i]) flag = false;
        }
        if (flag) break;

        sort(lines, lines + 3);
        if (lines[2]*lines[2] == (lines[0]*lines[0]) + (lines[1]*lines[1])) {
            cout << "right" << '\n';
        } else {
            cout << "wrong" << '\n';
        }
    }

    return 0;
}