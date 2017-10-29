// ==================================================
// Problem  :   1314 - Hidden Password
// Run time :   0.250 sec.
// Language :   C++11
// ==================================================


#include <cstdio>
#include <algorithm>
using namespace std;


const int MAXL = 100000 + 3;


struct suff {
    int idx;
    int rnk[2];
};


bool suff_cmp(const suff &a, const suff &b)
{
    if(a.rnk[0] == b.rnk[0])
        return a.rnk[1] < b.rnk[1];

    return a.rnk[0] < b.rnk[0];
}


int smallest_initial_pos(char str[], int len)
{
    suff suffixes[len];

    for(int i = 0; i < len; ++i) {
        suff &sf = suffixes[i];
        sf.idx = i;
        sf.rnk[0] = str[i];
        sf.rnk[1] = (i+1 < len)? str[i+1] : str[0];
    }

    stable_sort(suffixes, suffixes+len, suff_cmp);
    int idx_rnk[len];

    for(int k = 4; k < 2*len; k *= 2) {
        int prev_suff_rnk0 = -1;
        int prev_suff_rnk1 = -1;
        int rnk = -1;

        for(int i = 0; i < len; ++i) {
            suff &sf = suffixes[i];

            if(sf.rnk[0] == prev_suff_rnk0 and sf.rnk[1] == prev_suff_rnk1) {
                sf.rnk[0] = rnk;
            }
            else {
                prev_suff_rnk0 = sf.rnk[0];
                prev_suff_rnk1 = sf.rnk[1];
                sf.rnk[0] = ++rnk;
            }

            idx_rnk[sf.idx] = rnk;
        }

        for(int i = 0; i < len; ++i) {
            int next_idx = suffixes[i].idx + k/2;

            bool flag = false;
            if(next_idx >= len) {
                flag = true;
                next_idx %= len;
            }

            suffixes[i].rnk[1] = (flag and next_idx >= suffixes[i].idx)? -1 : idx_rnk[next_idx];
        }

        stable_sort(suffixes, suffixes+len, suff_cmp);
    }

    return suffixes[0].idx;
}


int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    while(t--) {
        int len;
        char str[MAXL];

        scanf("%d %s", &len, str);

        printf("%d\n", smallest_initial_pos(str, len));
    }

    return 0;
}


// -------------------- Alternatively --------------------
// Run time :   0.470 sec.
/*
#include <cstdio>
#include <algorithm>
using namespace std;


const int MAXL = 100000 + 3;


struct suff {
    int idx;
    int rnk[2];
};


bool suff_cmp(const suff &a, const suff &b)
{
    if(a.rnk[0] == b.rnk[0]) {
        if(a.rnk[1] == b.rnk[1]) {
            return a.idx < b.idx;
        }

        return a.rnk[1] < b.rnk[1];
    }

    return a.rnk[0] < b.rnk[0];
}


int smallest_initial_pos(char str[], int len)
{
    suff suffixes[len];

    for(int i = 0; i < len; ++i) {
        suff &sf = suffixes[i];
        sf.idx = i;
        sf.rnk[0] = str[i];
        sf.rnk[1] = (i+1 < len)? str[i+1] : str[0];
    }

    sort(suffixes, suffixes+len, suff_cmp);
    int idx_rnk[len];

    for(int k = 4; k < 2*len; k *= 2) {
        int prev_suff_rnk0 = -1;
        int prev_suff_rnk1 = -1;
        int rnk = -1;

        for(int i = 0; i < len; ++i) {
            suff &sf = suffixes[i];

            if(sf.rnk[0] == prev_suff_rnk0 and sf.rnk[1] == prev_suff_rnk1) {
                sf.rnk[0] = rnk;
            }
            else {
                prev_suff_rnk0 = sf.rnk[0];
                prev_suff_rnk1 = sf.rnk[1];
                sf.rnk[0] = ++rnk;
            }

            idx_rnk[sf.idx] = rnk;
        }

        for(int i = 0; i < len; ++i) {
            int next_idx = suffixes[i].idx + k/2;

            bool flag = false;
            if(next_idx >= len) {
                flag = true;
                next_idx %= len;
            }

            suffixes[i].rnk[1] = (flag and next_idx >= suffixes[i].idx)? -1 : idx_rnk[next_idx];
        }

        sort(suffixes, suffixes+len, suff_cmp);
    }

    return suffixes[0].idx;
}


int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    while(t--) {
        int len;
        char str[MAXL];

        scanf("%d %s", &len, str);

        printf("%d\n", smallest_initial_pos(str, len));
    }

    return 0;
}

*/


// N.B. :
// In first approach, I've used stable_sort() instead of sort().
// In second approach, I've used sort() but modified suff_cmp() function.
