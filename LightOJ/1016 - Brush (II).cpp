#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, tc;
    long int n, w, *arr, i, temp, move_cnt;

    scanf("%d", &t);
    tc = 0;

    while(t--) {
        scanf("%ld %ld", &n, &w);

        arr = new long int [n];

        for(i = 0; i < n; i++) scanf("%*ld %ld", arr+i);

        sort(arr, arr+n);

        temp = arr[0] + w;
        move_cnt = 1;

        for(i = 0; i < n; i++) {
            if(arr[i] > temp) {
                move_cnt++;
                temp = arr[i] + w;
            }
        }

        printf("Case %d: %ld\n", ++tc, move_cnt);

        delete [] arr;
    }

    return 0;
}
