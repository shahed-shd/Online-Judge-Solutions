// ==================================================
// Problem  :   Triplet Sum in Array
// Run time :   0.01 sec
// Language :   C
// ==================================================


#include <stdio.h>
#include <stdlib.h>


const int MAXN = 200 + 3;


int cmp(const void *a, const void *b)
{
    return ( *(int*)a - *(int*)b );
}


int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    int arr[MAXN];

    while(t--) {
        int n, x;
        scanf("%d %d", &n, &x);

        for(int i = 0; i < n; ++i)
            scanf("%d", arr+i);

        qsort(arr, n, sizeof(arr[0]), cmp);

        int found = 0;

        for(int i = 0; i < n && !found; ++i) {
            int need = x - arr[i];
            int l = i+1, r = n-1;

            while(l < r && !found) {
                int s = arr[l] + arr[r];

                if(s == need) found = 1;
                else if(s < need) ++l;
                else --r;
            }
        }

        puts(found? "1" : "0");
    }

    return 0;
}
