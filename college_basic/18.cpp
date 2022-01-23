#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

char ch[15];
int visit[15];
int L, C;

void check()
{
    string str;
    int vowel = 0;
    
    for (int i = 0; i < C; ++i) {
        if (visit[i]) {
            str += ch[i];
            if (ch[i] == 'a' || ch[i] == 'e' || ch[i] == 'i' || ch[i] == 'o' || ch[i] == 'u') {
                vowel++;
            }
        }
    }
    if (vowel && L - vowel >= 2) cout << str << '\n';
}

int make_pw(int idx, int cnt)
{
    if (cnt == L) {
        check();
        return 0;
    }
    if (idx == C) return 0;

    visit[idx] = 1;
    make_pw(idx + 1, cnt + 1);

    visit[idx] = 0;
    make_pw(idx + 1, cnt);

    return 0;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin >> L >> C;
    for (int i = 0; i < C; ++i) {
        cin >> ch[i];
    }
    sort(ch, ch+C);
    for (int i = 0; i <= C - L; ++i) {
        memset(visit, 0, sizeof(visit));
        visit[i] = 1;
        make_pw(i + 1, 1);
    }

    return 0;
}