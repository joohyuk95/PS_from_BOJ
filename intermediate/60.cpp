#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

#define endl '\n'

// Set up : Global Variables
/* None */

// Set up : Functions Declaration
/* None */


int main()
{
    // Set up : I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Set up : Input
    int N; cin >> N;
    string W[N];
    for (int i=0; i<N; i++)
        cin >> W[i];

    // Process
    /* 첫 번째 단어 multiset */
    multiset<char> fs(W[0].begin(), W[0].end());

    int ans = 0;
    for (int i=1; i<N; i++) {
        /* i > 0 번째 단어 multiset */
        multiset<char> is(W[i].begin(), W[i].end());

        multiset<char> f_is, i_fs; /* fs - is, is - fs */
        set_difference(fs.begin(), fs.end(), is.begin(), is.end(),
                       inserter(f_is, f_is.begin()));
        set_difference(is.begin(), is.end(), fs.begin(), fs.end(),
                       inserter(i_fs, i_fs.begin()));

        /* n(fs-is) <= 1 이고 n(is-fs) <= 1 이어야만 비슷한 단어 */
        if (f_is.size() <= 1 && i_fs.size() <= 1) ans++;
    }

    // Control : Output
    cout << ans << endl;
}