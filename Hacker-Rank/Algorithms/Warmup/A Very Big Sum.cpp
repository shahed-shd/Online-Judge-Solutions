#include <cstdio>
using namespace std;

typedef     long long       LL;

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
    LL n;

    while(~scanf("%lld", &n)) {
        LL num, sum = 0;

        while(n--) {
            num = fastIn<LL>();
            sum += num;
        }

        printf("%lld\n", sum);
    }

    return 0;
}

