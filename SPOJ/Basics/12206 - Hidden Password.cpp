// ==================================================
// Problem  :   12206 - Hidden Password
// Runtime  :   0.000 sec.
// Language :   C++14
// ==================================================

#include <cstdio>
#include <vector>
using namespace std;


inline bool bitcheck(int n, int pos) { return n & (1 << pos); }
inline int biton(int n, int pos) { return n | (1 << pos); }


void get_a_b(char str[], int &a, int &b)
{
    a = b = 0;

    for(int i = 0; i < 6; ++i) {
        if(bitcheck(str[i], i))
            a = biton(a, i);
        if(bitcheck(str[i], (i+3) % 6))
            b = biton(b, i);
    }
}


int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        vector<int> indices;
        char str[70];

        while(n--) {
            scanf("%s", str);

            int a, b;
            get_a_b(str, a, b);

            indices.push_back(a);
            indices.push_back(b);
        }

        scanf("%s", str);

        for(auto &idx : indices) putchar(str[idx]);
        putchar('\n');
    }

    return 0;
}
