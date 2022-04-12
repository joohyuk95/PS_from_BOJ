#include <iostream>
using namespace std;

int month, date, cnt;
string day;

int main()
{
    cin >> month >> date;

    while (--month) {
        switch (month) {
            case 2:
                cnt += 28;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                cnt += 30;
                break;
            default:
                cnt += 31;
                break;
        }    
    }
    cnt += date;

    switch (cnt % 7) {
        case 0: day = "SUN"; break;
        case 1: day = "MON"; break;
        case 2: day = "TUE"; break;
        case 3: day = "WED"; break;
        case 4: day = "THU"; break;
        case 5: day = "FRI"; break;
        case 6: day = "SAT"; break;
    }

    cout << day << '\n';
    return 0;
}