#include <cstdio>
using namespace std;

int main()
{
    int da, ma, ya, de, me, ye;
    scanf("%d %d %d %d %d %d", &da, &ma, &ya, &de, &me, &ye);

    int fine = 0;

    if(ya == ye && ma == me) {
        if(de < da) fine = (da - de) * 15;
    }
    else if(ya == ye) {     // ma != me
        if(me < ma) fine = (ma - me) * 500;
    }
    else if(ye < ya) fine = 10000;

    printf("%d\n", fine);

    return 0;
}
