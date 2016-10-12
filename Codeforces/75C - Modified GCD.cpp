// ==================================================
// Problem  :   75C - Modified GCD
// Run time :   0.062 sec.
// Language :   C++11
// ===================================================

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

vector<int> divisors;

int gcd(int m, int n)
{
    while(n != 0) {
        int t = m % n;
        m = n;
        n = t;
	}

    return m;
}

void get_divisors(int g)
{
    int rt = sqrt(g);

    for(int i = 1; i <= rt; ++i) {
        if(g % i == 0) {
            divisors.push_back(i);
            divisors.push_back(g/i);
        }
    }

    if(divisors.back() == rt) divisors.pop_back();  // rt appears twice.

    sort(divisors.begin(), divisors.end());
}

int main()
{
    //freopen("in", "r", stdin);

    int a, b;
    scanf("%d %d", &a, &b);

    get_divisors(gcd(a, b));

    int n;
    scanf("%d", &n);

    int low, high;

    while(n--) {
        scanf("%d %d", &low, &high);

        int idx = upper_bound(divisors.begin(), divisors.end(), high) - divisors.begin();

        printf("%d\n", ((idx > 0 && low <= divisors[idx-1])? divisors[idx-1] : -1));
    }

    return 0;
}
