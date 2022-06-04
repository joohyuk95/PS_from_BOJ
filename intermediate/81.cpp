#include <iostream>
using namespace std;

int a, b, v;
int dist, cnt;

int main()
{
    cin >> a >> b >> v;

    int day = (v - b - 1) / (a - b) + 1;
    
    cout << day << '\n';
    return 0;
}