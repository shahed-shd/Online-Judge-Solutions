// ==================================================
// Problem  :   754A - Lesha and array splitting
// Run time :   0.015 sec.
// Language :   C++11
// ==================================================

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n+3];
    int isNonZero = 0;

    for(int i = 1; i <= n; ++i) {
        scanf("%d", arr+i);
        if(arr[i]) ++isNonZero;
    }

    if(isNonZero == 1) {
        printf("YES\n1\n1 %d\n", n);
    }
    else if(isNonZero > 1) {
        int firstNonZero, lastNonZero;

        for(int i = 1; i <= n; ++i) {
            if(arr[i]) {
                firstNonZero = i;
                break;
            }
        }

        for(int i = n; i >= 1; --i) {
            if(arr[i]) {
                lastNonZero = i;
                break;
            }
        }

        int midSum = 0;

        for(int i = firstNonZero+1; i < lastNonZero; ++i)
            midSum += arr[i];

        if(midSum) {
            puts("YES\n3");
            printf("%d %d\n", 1, firstNonZero);
            printf("%d %d\n", firstNonZero+1, lastNonZero-1);
            printf("%d %d\n", lastNonZero, n);
        }
        else {
            puts("YES\n2");
            printf("%d %d\n", 1, lastNonZero-1);
            printf("%d %d\n", lastNonZero, n);
        }
    }
    else puts("NO");

    return 0;
}
