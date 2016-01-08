#include <iostream>
#include <unordered_map>
using namespace std;

string str;
unordered_map<char,char> rev;

bool isPalindrome()
{
    int first = 0, last = str.length() - 1;

    while(first < last)
        if(str[first++] != str[last--])
            return false;

    return true;
}

bool isMirrored()
{
    int first = 0, last = str.length() - 1;

    while(first <= last)
        if(rev[str[first++]] != str[last--])
            return false;

    return true;
}

int main()
{
    //freopen("in", "r", stdin);

    rev['A'] = 'A';
    rev['E'] = '3';
    rev['H'] = 'H';
    rev['I'] = 'I';
    rev['J'] = 'L';
    rev['L'] = 'J';
    rev['M'] = 'M';
    rev['O'] = 'O';
    rev['S'] = '2';
    rev['T'] = 'T';
    rev['U'] = 'U';
    rev['V'] = 'V';
    rev['W'] = 'W';
    rev['X'] = 'X';
    rev['Y'] = 'Y';
    rev['Z'] = '5';
    rev['1'] = '1';
    rev['2'] = 'S';
    rev['3'] = 'E';
    rev['5'] = 'Z';
    rev['8'] = '8';

    while(cin >> str) {
        bool m = isMirrored(), p = isPalindrome();

        if(m && p) cout << str << " -- is a mirrored palindrome.\n\n";
        else if(!m && p) cout << str << " -- is a regular palindrome.\n\n";
        else if(m && !p) cout << str << " -- is a mirrored string.\n\n";
        else cout << str << " -- is not a palindrome.\n\n";
    }

    return 0;
}
