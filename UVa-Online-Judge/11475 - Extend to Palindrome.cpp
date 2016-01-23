#include <iostream>
using namespace std;

void computeLPS(string& pat, int lps[])
{
    lps[0] = 0;

    int m = pat.length(), len = 0, i = 1;

    while(i < m) {
        if(pat[i] == pat[len])
            lps[i++] = ++len;
        else {
            if(len != 0)
                len = lps[len-1];
            else
                lps[i++] = 0;
        }
    }
}

int kmp(string& p, string& t)
{
    int n = t.length(), lps[n];

    computeLPS(p, lps);

    int i = 0, j = 0;

    while(i < n) {
        if(t[i] == p[j])
            ++i, ++j;

        if(i+j >= n)
            return i-j-1;
        else if(i < n && t[i] != p[j]){
            if(j != 0)
                j = lps[j-1];
            else
                ++i;
        }
    }

    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    string str;

    while(cin >> str) {
        string revStr(str.rbegin(), str.rend());

        int k = kmp(revStr, str);

        if(k < 0) cout << str << '\n';
        else {
            string temp = str.substr(0, k+1);
            cout << str << string(temp.rbegin(), temp.rend()) << '\n';
        }
    }

    return 0;
}
