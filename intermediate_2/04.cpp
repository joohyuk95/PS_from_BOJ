#include <iostream>
using namespace std;

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    if (str1 == str2) {
        cout << "24:00:00" << '\n';
        return 0;
    }
    int h1 = 10*(int(str1[0])-48) + int(str1[1])-48;
    int m1 = 10*(int(str1[3])-48) + int(str1[4])-48;
    int s1 = 10*(int(str1[6])-48) + int(str1[7])-48;

    int h2 = 10*(int(str2[0])-48) + int(str2[1])-48;
    int m2 = 10*(int(str2[3])-48) + int(str2[4])-48;
    int s2 = 10*(int(str2[6])-48) + int(str2[7])-48;

    int h, m, s;

    if (s2 >= s1) s = s2 - s1;
    else {
        m2--;
        s = 60+s2 - s1;
    }

    if (m2 >= m1) m = m2 - m1;
    else {
        h2--;
        m = 60+m2 - m1;
    }

    if (h2 >= h1) h = h2 - h1;
    else h = 24+h2 - h1;

    if (h < 10) cout << '0';
    cout << h << ':';

    if (m < 10) cout << '0';
	cout << m << ':';

    if (s < 10) cout << '0';
    cout << s << '\n';
    return 0;
}