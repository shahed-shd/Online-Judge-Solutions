// ==================================================
// Problem  :   7 Segment Display
// Run time :   0.088 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 1e4 + 3;

const int segCnt[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 5};
const int segNum[] = {0, 0, 1, 7, 4, 2, 0, 8};

int main()
{
    int t;
    scanf("%d", &t);

    char str[MAXN];

    while(t--) {
        int len;
        scanf("%d %s", &len, str);

        int tot = 0;
        for(int i = 0; i < len; ++i) tot += segCnt[str[i] - '0'];

        tot -= len * 2;

        int q = tot / 4;
        int r = tot % 4;

        if(q + bool(r) <= len) {
            int one = len - q - bool(r);

            int idx = 0;
            while(q--) str[idx++] = '0';
            while(one--) str[idx++] = '1';
            if(r) str[idx++] = segNum[r+2] + '0';
            str[idx] = '\0';
        }
        else {
            int zero = len;
            int eight = 0;

            r += (q - len) * 4;

            if(r) {
                eight = r;
                zero -= eight;
            }

            int idx = 0;
            while(zero--) str[idx++] = '0';
            while(eight--) str[idx++] = '8';
            str[idx] = '\0';
        }

        puts(str);
    }

    return 0;
}
