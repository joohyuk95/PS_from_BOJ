#include <iostream>
#include <queue>
#include <string>
using namespace std;

string ch[100];

void swap(int idx)
{
    string tmp = ch[idx];
    ch[idx] = ch[idx-1];
    ch[idx-1] = tmp;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> ch[i];

    int idx = 0;
    queue<int> Q;
    while (ch[idx] != "KBS1") {
        Q.push(1);
        idx++;
    }

    while (true) {
        if (idx == 0) break;
        swap(idx);
        Q.push(4);
        idx--;
    }

    while (ch[idx] != "KBS2") {
        Q.push(1);
        idx++;
    }

    while (true) {
        if (idx == 1) break;
        Q.push(4);
        idx--;
    }

    while (!Q.empty()) {
        cout << Q.front();
        Q.pop();
    }
    return 0;
}