#include <iostream>
#include <vector>
using namespace std;

int n, min_val = 50000;
int check[21];
int ability[21][21];

void team_make(int idx, int cnt)
{
    vector<int> start;
    vector<int> link;
    int start_score = 0;
    int link_score = 0;

    if (cnt == (n/2)) {
        for (int i = 0; i < n; ++i) {
            if (check[i] == true) start.push_back(i);
            else link.push_back(i);
        }
        for (int i = 0; i < (n/2); ++i) {
            for (int j = 0; j < (n/2); ++j) {
                start_score += ability[start[i]][start[j]];
                link_score += ability[link[i]][link[j]];
            }
        }
        if (abs(start_score - link_score) < min_val) {
            min_val = abs(start_score - link_score);
        }
        return;
    }
    for (int i = idx; i < n; ++i) {
        if (check[i]) continue;
        else {
            check[i] = true;
            team_make(i, cnt+1);
            check[i] = false;
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> ability[i][j];
        }
    }
    team_make(0, 0);

    cout << min_val << '\n';
    return 0;
}