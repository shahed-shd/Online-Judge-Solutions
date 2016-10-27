#include <cstdio>
using namespace std;

int main()
{
    int h, m, s;
    char a_or_p;

    while(scanf("%d:%d:%d%c%*c", &h, &m, &s, &a_or_p) != EOF) {
        if(a_or_p == 'A') {
            if(h == 12) h = 0;
        }
        else {      // a_or_p == 'P'.
            if(h != 12) h += 12;
        }

        printf("%02d:%02d:%02d\n", h, m, s);
    }

    return 0;
}
