#include <iostream>
#include <algorithm>
using namespace std;

bool mycmp(char x, char y)
{
    // x small letter, y capital letter.
    if(('a' <= x && x <= 'z' && 'A' <= y && y <= 'Z') && (x != y+32))
        return x < y+32;

    // x capital letter, y small letter.
    if(('A' <= x && x <= 'Z' && 'a' <= y && y <= 'z') && (x+32 !=  y))
        return x+32 < y;

    return x < y;
}

int main()
{
    int tc;
    string str;

    cin >> tc;

    while(tc--) {
        cin >> str;

        sort(str.begin(), str.end(), mycmp);

        cout << str << '\n';

        while(next_permutation(str.begin(), str.end(), mycmp))
            cout << str << '\n';
    }

    return 0;
}
