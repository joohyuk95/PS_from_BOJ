#include <iostream>
#include <string>
using namespace std;

typedef struct {
    int hour;
    int min;
    int sec;
}Time;

Time setTime(string time)
{
    return Time{stoi(time.substr(0, 2)),
                stoi(time.substr(3, 2)),
                stoi(time.substr(6, 2))
            };
}

void printTime(Time time)
{
    string hour = to_string(time.hour);
    string min = to_string(time.min);
    string sec = to_string(time.sec);

    hour = hour.length() == 1 ? '0' + hour : hour;
    min = min.length() == 1 ? '0' + min : min;
    sec = sec.length() == 1 ? '0' + sec : sec;

    cout << hour << ':' << min << ':' << sec << '\n';
}

int main()
{
    string cur_t, start_t;
    cin >> cur_t >> start_t;

    Time cur = setTime(cur_t);
    Time start = setTime(start_t);

    Time res;
    
    res.sec = start.sec - cur.sec;
    if (res.sec < 0) {
        res.sec += 60;
        start.min--;
    }

    res.min = start.min - cur.min;
    if (res.min < 0) {
        res.min += 60;
        start.hour--;
    }
    
    res.hour = start.hour - cur.hour;
    if (res.hour < 0) {
        res.hour += 24;
    }

    printTime(res);
    return 0;
}