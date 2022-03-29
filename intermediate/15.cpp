#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> v;

int main()
{
    string s;
    cin >> s;
    int len = s.length();

    for (int i = 0; i < len; ++i) {
        int a = s[i] - 48;
        v.push_back(a);
    }
    sort(v.begin(), v.end(), greater<>());
    
    for (int i = 0; i < len; ++i) {
        cout << v[i];
    }
    cout << '\n';
    return 0;
}