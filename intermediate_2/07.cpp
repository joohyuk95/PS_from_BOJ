#include <iostream>
#define PI 3.14159265359
using namespace std;

int main()
{
    int r;
    cin >> r;

    double euclidean = PI*(r*r);
    double taxi = 2*(r*r);

    cout << fixed;
    cout.precision(6);
    cout << euclidean << '\n';
    cout << taxi << '\n';
    return 0;
}