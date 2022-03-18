#include <iostream>
using namespace std;

int main()
{
    int x, y, w, h;
    cin >> x >> y >> w >> h;

    int x1 = (x < w - x) ? x : w - x;
    int y1 = (y < h - y) ? y : h - y;
    int res = (x1 < y1) ? x1 : y1;

    cout << res << '\n';
    return 0;
}