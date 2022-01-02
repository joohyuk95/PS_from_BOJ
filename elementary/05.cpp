#include <iostream>
using namespace std;

int digit2num(int a, int b, int c, int d)
{
    return a * 1000 + b * 100 + c * 10 + d;
}

int make_clockNum(int num)
{
    int arr[5], res = num;
    arr[1] = num / 1000;
    arr[2] = (num % 1000) / 100;
    arr[3] = (num % 100) / 10;
    arr[4] = num % 10;

    for (int i = 2; i <= 4; ++i) {
        int a, b, c, d, tmp;
        a = arr[(i + 3) % 4 + 1] * 1000;
        b = arr[i % 4 + 1] * 100;
        c = arr[(i + 1) % 4 + 1] * 10;
        d = arr[(i + 2) % 4 + 1];
        tmp = a + b + c + d;
        if (tmp < res) res = tmp;
    }
    return res;
}

bool is_clockNum(int num)
{
    int tmp = make_clockNum(num);
    if (tmp == num) return true;
    return false;
}

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int num = digit2num(a, b, c, d);
    int clockNum = make_clockNum(num);

    int cnt = 0;
    for (int i = 1111; i < clockNum; ++i) {
        if (is_clockNum(i)) cnt++;
    }
    cout << cnt + 1 << endl;
    return 0;
}