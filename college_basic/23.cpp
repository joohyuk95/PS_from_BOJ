#include <iostream>
using namespace std;

int n, k, ans;
int seq[100];
int tap[100];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        cin >> seq[i];
    }
    for (int i = 0; i < k; ++i) {
        bool plugin = false;
        // 이미 같은 것이 꽂혀있는지 체크
        for (int j = 0; j < n; ++j) {
            if (tap[j] == seq[i]) {
                plugin = true;
                break;
            }
        }
        if (plugin) continue;

        // 빈 공간이 있는지 체크
        for (int j = 0; j < n; ++j) {
            if (!tap[j]) {
                tap[j] = seq[i];
                plugin = true;
                break;
            }
        }
        if (plugin) continue;

        // 하나를 선택해서 뽑아야 하는 상황
        // 다시 안 쓰이거나 가장 나중에 쓰이는걸 뽑음
        int plugout;   // 뺄 곳의 인덱스
        int latest = 0;    // 가장 느린게 얼마나 느린지
        for (int j = 0; j < n; ++j) {
            int when = 1;
            for (int p = i + 1; p < k; ++p) { // j구에 꽂힌 기기가 다음번에 몇 번째에 또 사용되나
                //when++;     --> 여기 있으면 다시 안 쓰이는 거랑, 마지막 순서에 쓰이는 거를 구분할 수 없음
                if (tap[j] == seq[p]) break;
                when++;
            }
            if (when > latest) {
                plugout = j;
                latest = when;
            }
        }
        ans++;
        tap[plugout] = seq[i];
    }

    cout << ans << '\n';
    return 0;
}