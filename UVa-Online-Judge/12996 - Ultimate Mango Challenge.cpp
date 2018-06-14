// ==================================================
// Problem  :   12996 - Ultimate Mango Challenge
// Run time :   0.000 sec
// Language :   C++11
// ==================================================


#include <cstdio>
using namespace std;


const int MAXN = 10 + 3;


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int N, L;
        scanf("%d %d", &N, &L);

        int arr[MAXN], sum = 0;

        for(int i = 0; i < N; ++i) {
            scanf("%d", arr+i);
            sum += arr[i];
        }

        bool ans = true;
        int k;

        for(int i = 0; i < N; ++i) {
            scanf("%d", &k);
            if(arr[i] > k) ans = false;
        }

        if(sum > L) ans = false;

        printf("Case %d: %s\n", tc, (ans? "Yes" : "No"));
    }

    return 0;
}
