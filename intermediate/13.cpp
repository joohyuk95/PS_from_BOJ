#include <iostream>
using namespace std;

int x, y;

int Rev(int num)
{
    if (num < 10) return num;
    else if (10 <= num && num < 100) {
        int a = num / 10;
        int b = (num % 10) * 10;
        return a + b;
    } else if (100 <= num && num < 1000) {
        int a = num / 100;
        int b = ((num % 100) / 10) * 10;
        int c = (num % 10) * 100;
        return a + b + c;
    } else {
        int a = num / 1000;
        int b = ((num % 1000) / 100) * 10;
        int c = ((num % 100) / 10) * 100;
        int d = num % 10 * 1000;
        return a + b + c + d;
    }
}

int main()
{
    cin >> x >> y;
    
    cout << Rev(Rev(x) + Rev(y));
    return 0;
}