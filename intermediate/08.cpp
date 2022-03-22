#include <iostream>
using namespace std;

int x;

int main()
{
    cin >> x;

    int order_sum = 0;
    int order = 1;
    while (true) {
        order_sum += order;

        if (order_sum >= x) break;
        order++;
    }

    int index = x - (order_sum - order);
    if (order % 2) {
        cout << order + 1 - index << '/' << index << '\n';
    } else {
        cout << index << '/' << order + 1 - index << '\n';
    }

    return 0;
}