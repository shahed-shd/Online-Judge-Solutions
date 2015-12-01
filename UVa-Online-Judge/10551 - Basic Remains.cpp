#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

void print_as_base_b(int n, int b)
{
    if(n == 0) {
        putchar('0');
        return;
    }

    string res;

    while(n) {
        res.push_back(n % b);
        n /= b;
    }

    for(int i = res.length()-1; i >= 0; --i)
        putchar(res[i]+'0');
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int b;

    while(scanf("%d", &b) == 1 && b) {
        char str[1005];
        scanf(" %s ", str);

        char ch;
        int mod = 0;

        while(ch = getchar(), ch != '\n')
            mod = mod * b + ch - '0';

        int len = strlen(str);
        long long res = 0;

        for(int i = 0; i < len; ++i)
            res = (res * b + str[i] - '0') % mod;

        print_as_base_b(res, b);
        putchar('\n');
    }

    return 0;
}
