#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void add(string &num1, string &num2, string &str);
void subtract(string &num1, string &num2, string &str);
void output(string &num1, string &num2, string &str, string &sign);
void mul(string &num1, string &num2);

int main()
{
    short tc;
    string str;

    cin >> tc;

    while(tc--) {
        cin >> str;

        size_t signPos = str.find('+');
        if(signPos == string::npos) signPos = str.find('-');
        if(signPos == string::npos) signPos = str.find('*');

        string num1 = str.substr(0, signPos);
        string sign = str.substr(signPos, 1);
        string num2 = str.substr(signPos+1);

        if(sign == "+") {
            add(num1, num2, str);
            output(num1, num2, str, sign);
        }
        else if(sign == "-") {
            subtract(num1, num2, str);
            output(num1, num2, str, sign);
        }
        else mul(num1, num2);

        cout << '\n';
    }

    return 0;
}

void add(string &num1, string &num2, string &str)
{
    str.clear();
    short idx1 = num1.length();
    short idx2 = num2.length();
    short sum, carry = 0;

    while(max(idx1--, idx2--)) {
        sum = 0;
        if(idx1 >= 0) sum += num1[idx1] - '0';
        if(idx2 >= 0) sum += num2[idx2] - '0';
        sum += carry;

        carry = sum / 10;
        sum %= 10;

        str.push_back(sum+'0');
    }
    while(carry) {
        str.push_back((carry % 10) + '0');
        carry /= 10;
    }

    short lenRes = str.length();
    for(short i = 0; i < lenRes/2; ++i) swap(str[i], str[lenRes - i - 1]);    //reversing.
}

void subtract(string &num1, string &num2, string &str)
{
    str.clear();

    if(num1 == num2) {
       str.push_back('0');
       return;
    }

    short idx1 = num1.length();
    short idx2 = num2.length();
    short res, carry = 0;

    while(idx1--) {
        res = (--idx2 >= 0)? (num2[idx2]-'0') : 0;
        res += carry;
        carry = 0;
        if(res > num1[idx1]-'0') {
            res = (num1[idx1]-'0') + 10 - res;
            carry = 1;
        }
        else res = num1[idx1]-'0' - res;

        str.push_back(res + '0');
    }

    short lenRes = str.length();
    for(short i = 0; i < lenRes/2; ++i) swap(str[i], str[lenRes - i - 1]);    //reversing.

    while(str.length() > 1 && str.front() == '0') str.erase(0, 1);   // remove preceding zeros.
}

void output(string &num1, string &num2, string &str, string &sign)
{
    num2.insert(0, sign);
    short max_len = max(str.length(), max(num1.length(), num2.length()));
    string line(max(num2.length(), str.length()), '-');

    cout << setw(max_len) << num1 << '\n'
        << setw(max_len) << num2 << '\n'
        << setw(max_len) << line << '\n'
        << setw(max_len) << str << '\n';
}

void mul(string &num1, string &num2)
{
    string str;

    auto lambda = [num1, &str] (short n) mutable ->void {
                    short idx1 = num1.length();
                    int res, carry = 0;
                    str.clear();
                    while(idx1--) {
                        res = (num1[idx1]-'0') * n;
                        res += carry;

                        carry = res / 10;
                        res %= 10;
                        str.push_back(res+'0');
                    }
                    while(carry) {
                        str.push_back((carry%10) + '0');
                        carry /= 10;
                    }

                    short lenRes = str.length();
                    for(short i = 0; i < lenRes/2; ++i) swap(str[i], str[lenRes - i - 1]);    //reversing.

                    while(str.length() > 1 && str.front() == '0') str.erase(0, 1);   // remove preceding zeros.;
                };

    short len2 = num2.length();
    vector<string> v, v1;

    for(short i = len2-1; i >= 0; --i) {
        lambda(num2[i]-'0');
        v.push_back(str);
    }

    v1 = v;

    for(short i = 0; i < len2; ++i) {
        for(short j = 0; j < i; ++j) v1[i].push_back('0');
    }

    str.clear();
    str.push_back('0');
    string temp;

    for(short i = 0; i < len2; ++i) {
        add(str, v1[i], temp);
        str = temp;
    }
    while(str.length() > 1 && str.front() == '0') str.erase(0, 1);   // remove preceding zeros.

    // Now, output.

    num2.insert(0, "*");
    string lines;
    short max_len = max(str.length(), max(num1.length(), num2.length()));

    cout << setw(max_len) << num1 << '\n'
        << setw(max_len) << num2 << '\n';

    if(num2.length() > 2) {
        lines.assign(max(num2.length(), v[0].length()), '-');
        cout << setw(max_len) << lines << '\n';
        for(short i = 0; i < len2; ++i) cout << setw(max_len-i) << v[i] << '\n';
        lines.assign(max(v[v.size()-1].length(), str.length()), '-');
    }
    else lines.assign(max(num2.length(), str.length()), '-');

    cout << setw(max_len) << lines << '\n'
        << setw(max_len) << str << '\n';
}
