#include <iostream>
using namespace std;

struct Info {
    int code, gold, silver, bronze; 
};

Info medal[1001];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        medal[i] = {a, b, c, d};    
    }
    
    int idx;
    for (int i = 1; i <= n; ++i) {
        if (medal[i].code == k) {
            idx = i;
            break;
        }
    }

    int rank = 1;
    for (int i = 1; i <= n; ++i) {
        if (medal[i].gold > medal[idx].gold) {
            rank++;
        } else if (medal[i].gold == medal[idx].gold && medal[i].silver > medal[idx].silver) {
            rank++;
        } else if (medal[i].gold == medal[idx].gold && medal[i].silver == medal[idx].silver && medal[i].bronze > medal[idx].bronze) {
            rank++;
        }
    }
    cout << rank << endl;
    return 0;
}