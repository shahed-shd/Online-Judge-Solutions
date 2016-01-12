#include <iostream>
using namespace std;

int n;
string str;
bool flag;

void f(int s, int t, int sum)
{
    if(flag) return;
    if(str.substr(s, 4) == "()()" && sum == n) {
        flag = true;
        return;
    }
    if(s+1 == t) return;

    int num = 0;
    ++s, --t;

    bool sign = true;
    if(str[s] == '-') {
        sign = false;
        ++s;
    }

    while(str[s] != '(') {
        num *= 10;
        num += str[s++] - '0';
    }

    sum += (sign)? num : -num;

    int s1 = s, cnt = 1;

    while(cnt) {
        ++s1;
        if(str[s1] == '(') ++cnt;
        else if(str[s1] == ')') --cnt;
    }

    f(s, s1, sum);
    f(s1+1, t, sum);
}

int main()
{
    ios::sync_with_stdio(false);

    while(cin >> n) {
        str.clear();

        char ch;
        int countParenthesis = 0;

        cin >> ch;
        str.push_back(ch);
        ++countParenthesis;

        while(countParenthesis) {
            cin >> ch;
            str.push_back(ch);
            if(ch == '(') ++countParenthesis;
            if(ch == ')') --countParenthesis;
        }

        flag = false;
        f(0, str.length()-1, 0);

        (flag)? cout << "yes\n" : cout << "no\n";
    }

    return 0;
}
