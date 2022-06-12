#include <iostream>
#include <string>
using namespace std;

string list[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
int cnt[8];

int main()
{
    string str;
    cin >> str;

    for (int i = 0; i < str.size(); ++i) {
        for (int j = 0; j < 8; ++j) {
            if (str.substr(i, list[j].size()) == list[j]) {
                cnt[j]++;
            }
        }
    }
    
    int sum = 0;
    for (int i = 0; i < 8; ++i) {
        sum += cnt[i];
    }
    
    cout << str.size() - sum << '\n';
    return 0;
}