#include <iostream>
using namespace std;

int main()
{
    while (true) {
        string s;
        getline(cin, s);
        if (s == "#") break;

        int quicksum = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') continue;

            quicksum += (i+1)*(int(s[i])-64);
        }
        cout << quicksum << '\n';
    }
    return 0;
}