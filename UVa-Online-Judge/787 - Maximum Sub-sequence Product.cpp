#include <iostream>
#include <vector>
using namespace std;

class bigInt {
    char sign;
    string str;
public:
    bigInt(int n = 0) {
        if(n < 0) { sign = '-'; n *= -1; } else sign = '+';

        if(n == 0) str.push_back(0);
        while(n) { str.push_back(n%10); n /= 10; }

        int len = str.length(); for(int i = 0; i < len/2; ++i) swap(str[i], str[len-i-1]);
    }

    friend short comp(bigInt ob1, bigInt ob2) {
        auto comp_abs_value = [] (bigInt ob1, bigInt ob2) {
                        if(ob1.str.length() > ob2.str.length()) return 1;
                        if(ob1.str.length() < ob2.str.length()) return -1;
                        else {
                            int len = ob1.str.length();
                            for(int i = 0; i < len; ++i) {
                                if(ob1.str[i] > ob2.str[i]) return 1;
                                if(ob1.str[i] < ob2.str[i]) return -1;
                            }
                            return 0;
                        }
                    };

        if(ob1.sign == '+' && ob2.sign == '+') return comp_abs_value(ob1, ob2);
        if(ob1.sign == '+' && ob2.sign == '-') return 1;
        if(ob1.sign == '-' && ob2.sign == '+') return -1;
        return 0 - comp_abs_value(ob1, ob2);    // both are negative.
    }

    bigInt operator=(bigInt ob) {
        sign = ob.sign;
        str = ob.str;
        return *this;
    }

    bigInt operator*(bigInt ob) {
        auto mul = [] (string str, int n) {     // str * n
                        string res;
                        int len = str.length(), carry = 0, r;

                        for(int i = len-1; i >= 0; --i) {
                            r = str[i] * n + carry;
                            res.push_back(r%10);
                            carry = r / 10;
                        }
                        while(carry) {
                            res.push_back(carry%10);
                            carry /= 10;
                        }

                        len = res.length(); for(int i = 0; i < len/2; ++i) swap(res[i], res[len-i-1]); // reversing.

                        while(res.length() > 1 && res.front() == 0) res.erase(0, 1);   // removing the preceding zeros if any.

                        return res;
                    };

        auto add = [](string str1, string str2) {    // str1 + str2
                        string str;
                        int len1 = str1.length(), len2 = str2.length(), r, carry = 0;

                        while(len1 || len2) {
                            r = carry;
                            if(len1 > 0) r += str1[--len1];
                            if(len2 > 0) r += str2[--len2];

                            str.push_back(r%10);
                            carry = r / 10;
                        }
                        while(carry) {
                            str.push_back(carry%10);
                            carry /= 10;
                        }

                        len1 = str.length(); for(int i = 0; i < len1/2; ++i) swap(str[i], str[len1-i-1]); // reversing.

                        while(str.length() > 1 && str.front() == 0) str.erase(0, 1);   // removing the preceding zeros if any.

                        return str;
                    };

        string res, temp;
        int len = ob.str.length();

        for(int i = len-1; i >= 0; --i) {
            temp = mul(str, ob.str[i]);
            int j = len-1-i;
            while(j--) temp.push_back(0);

            res = add(res, temp);
        }

        bigInt bi;
        bi.str = res;

        if(sign == ob.sign) bi.sign = '+';
        else bi.sign = '-';

        return bi;
    }

    friend ostream& operator<<(ostream& strm, bigInt ob) {
        if(ob.sign == '-') strm << '-';
        int len = ob.str.length();
        for(int i = 0; i < len; ++i) strm << int(ob.str[i]);
        return strm;
    }
};

int main()
{
    int n;
    vector<bigInt> v;

    while(cin >> n) {
        v.clear();
        v.push_back(bigInt(n));

        while(cin >> n, n != -999999) v.push_back(bigInt(n));

        int sz = v.size();
        bigInt ans = v.front(), temp;

        for(int i = 0; i < sz; ++i) {
            temp = v[i];
            if(comp(temp, ans) == 1) ans = temp;

            for(int j = i+1; j < sz; ++j) {
                temp = temp * v[j];
                if(comp(temp, ans) == 1) ans = temp;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
