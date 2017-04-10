// ==================================================
// Problem  :   Rahul lucky-unlucky
// Runtime  :   0.083 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d",  &n);

        char ch[2];
        int opCnt = 0;
        vector<int> V;
        bool toFlip = false;

        for(int i = 1; i <= n; ++i) {
            scanf("%s", ch);

            if(toFlip) {
                ch[0] = (ch[0] == 'H')? 'T' : 'H';
                toFlip = false;
            }

            if(ch[0] == 'T') {
                ++opCnt;
                V.push_back(i);
                toFlip = true;
            }
        }

        printf("%d\n", opCnt);

        int sz = V.size();

        if(sz) printf("%d", V[0]);

        for(int i = 1; i < sz; ++i)
            printf(" %d", V[i]);

        putchar('\n');
    }

    return 0;
}
