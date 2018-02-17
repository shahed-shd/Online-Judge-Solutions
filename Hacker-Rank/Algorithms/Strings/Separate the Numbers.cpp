// ==================================================
// Problem  :   Separate the Numbers
// Score    :   20 /20
// Language :   C++14
// ==================================================

#include <cstdio>
using namespace std;


typedef     long long       LL;


const int MAXL = 32 + 3;


int split(int arr[], int len)
{
    LL a = 0;
    int upto = len / 2;

    for(int init_num_len = 1; init_num_len <= upto; ++init_num_len) {
        a = a * 10 + arr[init_num_len-1];
        if(init_num_len > 1 and arr[0] == 0) break;     // a contains leading zero.

        LL b, c = a;
        int curr_idx = init_num_len;

        do {
            if(arr[curr_idx] == 0) break;   // number contains leading zero.

            b = c;
            c = 0;

            while(curr_idx < len and c <= b)
                c = c * 10 + arr[curr_idx++];

        } while(curr_idx < len and b+1 == c);

        if(curr_idx == len and b+1 == c) {
            return init_num_len;
        }
    }

    return 0;   // Found no valid initial number after splitting the given number maintaining given rules.
}


int main()
{
    //freopen("in.txt", "r", stdin);

    int q;
    scanf("%d", &q);

    while(q--) {
        char s[MAXL];
        scanf("%s", s);

        // Split the string into digits.
        int arr[MAXL], len = 0;

        for(len = 0; s[len]; ++len)
            arr[len] = s[len] - '0';

        // Find the initial number length after splitting the the given number maintaining the given rules.
        int init_num_len = split(arr, len);

        // Output.
        if(init_num_len) {
            s[init_num_len] = '\0';
            printf("YES %s\n", s);
        }
        else puts("NO");
    }

    return 0;
}
