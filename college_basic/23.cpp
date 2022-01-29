// k번 반복
// 1. 비어있음
// 2. 같은 행동
// 3. 바꿔 꼽기

#include <iostream>
#include <vector>
using namespace std;

int n, k;
int seq[100];
int tab[100];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        cin >> seq[i];
    }
    for (int i = 0; i < k; ++i) {
        bool plugin = false;
        
        for (int j = 0; j < k; ++j) {
            if (!tab[j]) {
                tab[j] = seq[i];
                plugin = true;
                break;
            }
        }
        if (plugin) continue;

        for (int j = 0; j < k; ++j) {
            if (tab[j] == seq[i]) {
                plugin = true;
                break;
            }
        }
        if (plugin) continue;

        for (int j = 0; j < n; ++j) {
            
        }

    }


    return 0;
}