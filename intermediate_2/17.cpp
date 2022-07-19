#include <iostream>
using namespace std;

int main()
{
    while (true) {
        string bit; cin >> bit;
        if (bit == "#") break;

        int cnt = 0;
        for (int i = 0; i < bit.size()-1; ++i) {
            if (bit[i] == '1') cnt++;
        }
        if (cnt % 2) {
            if (bit[bit.size()-1] == 'e') bit[bit.size()-1] = '1';
            else bit[bit.size()-1] = '0';
        } else {
            if (cnt == 0) {
                if (bit[bit.size()-1] == 'e') bit[bit.size()-1] = '0';
                else bit[bit.size()-1] = '1';
            } else if (bit[bit.size()-1] == 'e') {
                bit[bit.size()-1] = '0';
            } else bit[bit.size()-1] = '1';
        }
        cout << bit << '\n';
    }

    return 0;
}