#include <cstdio>
#include <cmath>
using namespace std;

bool is_prime(int n)
{
    if(n < 2) return false;
    if(n == 2) return true;
    if(n % 2 == 0) return false;

    int s = sqrt(n);
    for(int i = 3; i <= s; i+=2) {
        if(n % i == 0) return false;
    }
    return true;
}

int main()
{
    short t;
    scanf("%hd", &t);


    while(t--) {
        int m, n;

        scanf("%d %d", &m, &n);

        for(int i = m; i <= n; ++i) {
            if(is_prime(i)) printf("%d\n", i);
        }

        if(t) printf("\n");
    }


    return 0;
}
