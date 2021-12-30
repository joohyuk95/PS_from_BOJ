#include <iostream>
using namespace std;

int cnt, maxi, mini = 100;
bool map[101][101];

int main()
{
    for (int k = 0; k < 4; ++k) {
        int x1, y1, x2, y2, tmp;
        cin >> x1 >> y1 >> x2 >> y2;
        
        tmp = (x1 < y1) ? x1 : y1;
        mini = (tmp < mini) ? tmp : mini;
        tmp = (x2 > y2) ? x2 : y2;
        maxi = (tmp > maxi) ? tmp : maxi; 
    
        for (int i = x1; i < x2; ++i) {
            for (int j = y1; j < y2; ++j) {
                map[i][j] = true;
            }
        }
    }
    
    for (int i = mini; i < maxi; ++i) {
        for (int j = mini; j < maxi; ++j) {
            if (map[i][j]) cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}