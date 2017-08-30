// ==================================================
// Problem  :   12543 - Longest Word
// Run time :   0.000 sec.
// Language :   C++11
// ==================================================

#include<cstdio>
using namespace std;

const int MAXN = 10000 + 3;

int main()
{
    //freopen("in.txt", "r", stdin);

    char str[MAXN] = {0};

    fread(str, sizeof(str[0]), MAXN, stdin);

    int s = -1, t, ss, tt, word_mx_len = 0;

    for(int i = 0; str[i]; ++i) {
        if(('A' <= str[i] && str[i] <= 'Z') || ('a' <= str[i] && str[i] <= 'z') || str[i] == '-') {
            if(s == -1) s = i;
            t = i;
        }
        else {
            if(s != -1 && t - s + 1 > word_mx_len)
                ss = s, tt = t, word_mx_len = t - s + 1;

            s = -1;
        }
    }

    for(int i = ss; i <= tt; ++i)
        putchar(('A' <= str[i] && str[i] <= 'Z')? str[i] + 32 : str[i]);
    putchar('\n');

    return 0;
}
