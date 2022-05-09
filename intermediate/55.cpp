#include <iostream>
using namespace std;

int hour, minuite, second;
int cooking;

int main()
{
    cin >> hour >> minuite >> second >> cooking;

    int H = cooking / 3600;
    int M = (cooking % 3600) / 60;
    int S = (cooking % 3600) % 60;

    int a = hour + H;
    int b = minuite + M;
    int c = second + S;

    if (c / 60) b++;
    if (b / 60) a++;

    a %= 24;
    b %= 60;
    c %= 60;
    
    cout << a << ' ' <<  b << ' ' << c << '\n';
    return 0;
}