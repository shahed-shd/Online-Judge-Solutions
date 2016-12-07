// ==================================================
// Problem  :   Unique partitions
// Run time :   0.086 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
using namespace std;

const int MAXN = 30 + 3;

int arr[MAXN];

int main()
{
    int t;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);

        int k = 0;
        arr[k] = n;
        bool space = false;

        while(true) {
            for(int i = 0; i <= k; ++i) {
                if(space) putchar(' ');
                space = true;

                printf("%d", arr[i]);
            }

            int remVal = 0;

            while(k >= 0 && arr[k] == 1)
                ++remVal, --k;

            if(k < 0) {
                putchar('\n');
                break;
            }

            --arr[k];
            ++remVal;

            while(arr[k] < remVal) {
                arr[k+1] =  arr[k];
                remVal -= arr[k];
                ++k;
            }

            arr[++k] = remVal;
        }
    }

    return 0;
}
