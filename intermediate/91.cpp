#include <iostream>
using namespace std;

char vowel[5] = {'a', 'e', 'i', 'o', 'u'};

int main()
{
    string str;
    getline(cin, str);
    
    string origin = "";
    for (int i = 0; i < str.size(); ++i) {
        bool flag = false;
        for (int j = 0; j < 5; ++j) {
            if (str[i] == vowel[j]) {
                flag = true;
                origin += str[i];
                i += 2;
                break;
            }
        }
        if (!flag) origin += str[i];
    }
    cout << origin << '\n';

    return 0;
}