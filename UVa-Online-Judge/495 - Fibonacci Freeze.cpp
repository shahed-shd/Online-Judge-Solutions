#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class BigNum {
    vector<string> memo;
    int calculated = 1;

    string add(const string &a, const string &b) {
        int idx_a = a.length() - 1, idx_b = b.length() - 1;

        string sum;
        int res, carry = 0;

        while(idx_a >= 0 || idx_b >= 0) {
            int x = (idx_a >= 0)? a[idx_a--] - '0' : 0;
            int y = (idx_b >= 0)? b[idx_b--] - '0' : 0;

            res = x + y + carry;

            carry = res / 10;
            res %= 10;

            sum.push_back(res + '0');
        }
        while(carry) {
            sum.push_back((carry % 10) + '0');
            carry /= 10;
        }

        reverse(sum.begin(), sum.end());

        return sum;
    }

public:

    BigNum() {
        memo.push_back(string("0"));
        memo.push_back(string("1"));
    }

    string get_fib(int n) {
        if(n <= calculated) return memo[n];

        for(int i = calculated+1; i <= n; ++i)
            memo.push_back(add(memo[i-1], memo[i-2]));

        calculated = n;

        return memo[n];
    }
};

int main()
{
    BigNum fib;

    int n;

    while(scanf("%d", &n) != EOF)
        printf("The Fibonacci number for %d is %s\n", n, fib.get_fib(n).c_str());

    return 0;
}
