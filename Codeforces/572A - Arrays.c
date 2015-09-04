#include <stdio.h>

int main()
{
    int nA, nB, k, m, keyA, keyB, i;

    scanf("%d %d %d %d", &nA, &nB, &k, &m);

    for(i = 1; i < k; ++i) scanf("%*d");
    scanf("%d", &keyA);
    for(i = k+1; i <= nA; ++i) scanf("%*d");

    for(i = 1; i <= nB-m; ++i) scanf("%*d");
    scanf("%d", &keyB);
    for(i = nB-m+2; i <= nB; ++i) scanf("%*d");

    if(keyA < keyB) printf("YES\n");
    else printf("NO\n");

    return 0;
}
