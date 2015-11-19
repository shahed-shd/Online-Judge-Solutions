#include <cstdio>
#include <string>
#include <vector>
using namespace std;

const int MAX_A = 15;

string str_add_str(string rev_s1, string rev_s2);
string str_multiply_int(string rev_num, int m);

class a_pow_i {
    vector<string> table[MAX_A+1];
    int counted[MAX_A+1] = {0};
public:
    a_pow_i() {
        string s(1, 1);
        for(int i = 0; i <= MAX_A; ++i) table[i].push_back(s);
    }

    string get_a_pow_i(int a, int p) {
        if(p <= counted[a]) return table[a][p];
        else {
            for(int i = counted[a]+1; i <= p; ++i)
                table[a].push_back(str_multiply_int(table[a][i-1], a));

            counted[a] = p;
            return table[a][p];
        }
    }
} p;


class i_multiply_a_pow_i {
    vector<string> table[MAX_A+1];
    int counted[MAX_A+1] = {0};
public:
    i_multiply_a_pow_i() {
        string s(1, 0);
        for(int i = 0; i <= MAX_A; ++i) table[i].push_back(s);
    }

    string get_i_multiply_a_pow_i(int n, int a) {
        if(n <= counted[a]) return table[a][n];
        else {
            string s;
            for(int i = counted[a]+1; i <= n; ++i) {
                s = p.get_a_pow_i(a, i);
                s = str_multiply_int(s, i);
                table[a].push_back(str_add_str(s, table[a][i-1]));
            }

            counted[a] = n;
            return table[a][n];
        }
    }
} r;


int main()
{
    int n, a;

    while(scanf("%d %d", &n, &a) == 2) {
        string rev_num(r.get_i_multiply_a_pow_i(n, a));
        int len = rev_num.length();

        while(len--) putchar(rev_num[len]+'0');
        putchar('\n');
    }

    return 0;
}


string str_multiply_int(string rev_num, int m)
{
    string ret;
    int len = rev_num.length(), res, carry = 0;

    for(int i = 0; i < len; ++i) {
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

string str_add_str(string rev_s1, string rev_s2)
{
    string ret;
    int len1 = rev_s1.length(), len2 = rev_s2.length();
    int len = max(len1, len2), res, carry = 0;

    for(int i = 0; i < len; ++i) {
        res = (i < len1)? rev_s1[i] : 0;
        res += (i < len2)? rev_s2[i] : 0;
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
