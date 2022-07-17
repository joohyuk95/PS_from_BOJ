#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    while (true) {
        string a, b;
        cin >> a >> b;
        if (a == "0" && b == "0") break;

        string longer = a.size() > b.size() ? a : b;
        string shorter = longer == a ? b : a;

        int diff = longer.size()-shorter.size();
        int cnt = 0;
        bool flag = false;
        for (int i = longer.size()-1; i >= 0; --i) {
            if (i >= diff) {
                if (int(longer[i])-48 + int(shorter[i-diff])-48 >= 10) {
                    cnt++;
                    flag = true;
                } else if (flag && int(longer[i])-48 + int(shorter[i-diff])-48 == 9) {
                    cnt++;
                    flag = true;
                } else {
                    flag = false;
                }
            } else {
                if (flag && int(longer[i])-48 + 1 == 10) cnt++;
                else flag = false;
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}