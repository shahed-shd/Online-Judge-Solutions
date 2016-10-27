#include <cstdio>
using namespace std;

template<class T>
inline T fastIn()
{
    register char c = 0;
    register T a = 0;
    bool neg = false;

    while(c < 33) c = getchar();

    if(c == '-') neg = true;
    else a = c - '0';

    while(c = getchar(), c > 33)
        a = a * 10 + (c - '0');

    return (neg? -a : a);
}

int main()
{
    //freopen("in", "r", stdin);

    int n;

    while(~scanf("%d", &n)) {
        int num, pos = 0, neg = 0, zeros = 0;

        for(int i = 0; i < n; ++i) {
            num = fastIn<int>();

            if(num > 0) ++pos;
            else if (num < 0) ++neg;
            else ++zeros;
        }

        printf("%.6f\n%.6f\n%.6f\n", 1.0*pos/n, 1.0*neg/n, 1.0*zeros/n);
    }

    return 0;
}
