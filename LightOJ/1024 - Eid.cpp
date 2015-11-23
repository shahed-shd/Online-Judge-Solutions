#include <cstdio>
#include <map>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

typedef     pair<int,int>   ii;

const int MAX_X = 10000;
vector<ii> primeNumbers;

bool isPrime(int n)
{
    if(n < 2) return false;
    if(n == 2) return true;
    if(!(n % 2)) return false;

    int s = sqrt(n);
    for(int i = 3; i <= s; i += 2)
        if(!(n % i)) return false;

    return true;
}

void factorize(int n)
{
    map<int,int> mp;
    map<int,int>::iterator it;

    int sz = primeNumbers.size();

    for(int i = 0; i < sz && n != 1; ++i) {
        if(!(n % primeNumbers[i].first)) {
            n /= primeNumbers[i].first;
            ++mp[i];
            i = -1;
        }
    }

    for(it = mp.begin(); it != mp.end(); ++it)
        primeNumbers[it->first].second = max(primeNumbers[it->first].second, it->second);
}

string str_mul_int(string rev_num, int m)
{
    string ret;
    int sz = rev_num.length(), res, carry = 0;

    for(int i = 0; i < sz; ++i) {
        res = rev_num[i] * m;
        res += carry;

        ret.push_back(res % 10);
        carry = res / 10;
    }
    while(carry) {
        ret.push_back(carry % 10);
        carry /= 10;
    }

    return ret;
}

int main()
{
    primeNumbers.push_back(ii(2, 0));  // 2 is the only even number which is prime.
    for(int i = 3; i <= MAX_X; i+=2)
        if(isPrime(i)) primeNumbers.push_back(ii(i, 0));

    // ------------------------------

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n, x;
        scanf("%d", &n);

        while(n--) {
            scanf("%d", &x);
            factorize(x);
        }

        int sz = primeNumbers.size();
        string str(1, 1);

        for(int i = 0; i < sz; ++i) {
            while(primeNumbers[i].second) {
                str = str_mul_int(str, primeNumbers[i].first);
                --primeNumbers[i].second;
            }
        }

        printf("Case %d: ", tc);
        for(int i = str.length()-1; i >= 0; --i) printf("%d", str[i]);
        putchar('\n');
    }

    return 0;
}
