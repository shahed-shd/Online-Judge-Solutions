#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

void factorize(int num, int left)
{
    vector<int> factors;

    int rt = sqrt(num);

    for(int i = 1; i <= rt; ++i) {
        if(num % i == 0) {
            int tmp = num / i;

            if(i > left) factors.push_back(i);
            if(tmp > left && i != tmp) factors.push_back(tmp);
        }
    }

    sort(factors.begin(), factors.end());

    for(vector<int>::iterator it = factors.begin(); it != factors.end(); ++it)
        printf(" %d", *it);

    putchar('\n');
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int piaju, left;
        scanf("%d %d", &piaju, &left);
        int eaten = piaju - left;

        printf("Case %d:", tc);

        if(eaten <= left) {
            puts(" impossible");
            continue;
        }

        factorize(eaten, left);
    }

    return 0;
}
