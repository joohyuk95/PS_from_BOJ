#include <iostream>
#include <string>
using namespace std;

string H, M;

int main()
{
    cin >> H >> M;
    
    int h = stoi(H);
    int m = stoi(M);

    if (m >= 45) {
        cout << h << ' ' << m-45 << '\n';
        return 0;
    }

    if (h == 0) {
        cout << 23 << ' ' << 60+m-45 << '\n';
    } else {
        cout << h-1 << ' ' << 60+m-45 << '\n';
    }

    return 0;
}