#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;

typedef     pair<int,int>   ii;

struct term {
    int coefficient, xPow, yPow;

    term(int c = 0, int x = 0, int y = 0) { coefficient = c, xPow = x, yPow = y; }

    term(string str) {
        int len = str.length();
        int x_pos = -1, y_pos = -1;

        for(int i = 0; i < len; ++i) {
            if(str[i] == 'x') x_pos = i;
            else if(str[i] == 'y') y_pos = i;
        }

        if(x_pos == -1)
            x_pos = str.length(), str.push_back('x'), str.push_back('0');

        if(y_pos == -1)
            y_pos = str.length(), str.push_back('y'), str.push_back('0');

        if(min(x_pos, y_pos) == 0)
            str.insert(0, 1, '1'), ++x_pos, ++y_pos;
        else if(min(x_pos, y_pos) == 1 && (str.front() == '+' || str.front() == '-'))
            str.insert(1, 1, '1'), ++x_pos, ++y_pos;

        int pos = min(x_pos, y_pos);

        if(str[pos+1] < '0' || '9' < str[pos+1])
            str.insert(pos+1, 1, '1'), pos = max(x_pos, y_pos)+1;

        pos = max(pos, max(x_pos, y_pos));
        if(pos == int(str.length()-1))
            str.push_back('1');

        char ch1, ch2;

        sscanf(str.c_str(), "%d%c%d%c%d", &coefficient, &ch1, &xPow, &ch2, &yPow);

        if(ch1 != 'x')
            swap(xPow, yPow);
    }

    term operator*(term &ob) {
        term res;

        res.coefficient = coefficient * ob.coefficient;
        res.xPow = xPow + ob.xPow;
        res.yPow = yPow + ob.yPow;

        return res;
    }

    bool operator<(const term &ob) const {
        if(xPow > ob.xPow) return true;
        else if(xPow < ob.xPow) return false;
        else {
            return (yPow < ob.yPow);
        }
    }
};

void get_polynomial_terms(char input[], vector<term> &polynomial)
{
    string str;
    str.push_back(input[0]);

    for(int i = 1; input[i]; ++i) {
        if(input[i] != '+' && input[i] != '-') {
            str.push_back(input[i]);
        }
        else {
            polynomial.push_back(term(str));
            str.clear();
            str.push_back(input[i]);
        }
    }
    polynomial.push_back(term(str));
}

void catenate_int(string &str, int n)
{
    char cstr[10];
    sprintf(cstr, "%d", n);
    str += cstr;
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    char input[100];

    while(scanf("%s", input), input[0] != '#') {
        vector<term> polynomial1, polynomial2;
        get_polynomial_terms(input, polynomial1);

        scanf("%s", input);
        get_polynomial_terms(input, polynomial2);

        map<ii, int> mp;

        for(auto& trm1 : polynomial1) {
            for(auto& trm2 : polynomial2) {
                term mul = trm1 * trm2;
                mp[ii(mul.xPow, mul.yPow)] += mul.coefficient;
            }
        }

        vector<term> product;

        for(auto& pr : mp)
            product.push_back(term(pr.second, pr.first.first, pr.first.second));

        sort(product.begin(), product.end());

        string str;

        if(product[0].coefficient) {
            int tmp = product[0].coefficient;

            if(tmp < 0)
                str.push_back('-'), tmp = -tmp;

            if(tmp != 1 || (tmp == 1 && product[0].xPow == 0 && product[0].yPow == 0))
                catenate_int(str, tmp);

            if(product[0].xPow) str.push_back('x');
            if(product[0].xPow > 1) catenate_int(str, product[0].xPow);

            if(product[0].yPow) str.push_back('y');
            if(product[0].yPow > 1) catenate_int(str, product[0].yPow);

            str.push_back(' ');
        }

        int sz = product.size();

        for(int i = 1; i < sz; ++i) {
            if(!product[i].coefficient) continue;

            int tmp = product[i].coefficient;

            if(tmp < 0)
                str.push_back('-'), tmp = -tmp;
            else
                str.push_back('+');

            str.push_back(' ');

            if(tmp != 1 || (tmp == 1 && product[i].xPow == 0 && product[i].yPow == 0))
                catenate_int(str, tmp);

            if(product[i].xPow) str.push_back('x');
            if(product[i].xPow > 1) catenate_int(str, product[i].xPow);

            if(product[i].yPow) str.push_back('y');
            if(product[i].yPow > 1) catenate_int(str, product[i].yPow);

            str.push_back(' ');
        }

        if(str.empty()) {
            puts("\n0");
            continue;
        }

        str.pop_back();

        int len = str.length();

        string strExp(len, ' ');

        for(int i = 0; i < len; ++i) {
            if(str[i] == 'x' || str[i] == 'y') {
                ++i;

                while('0' <= str[i] && str[i] <= '9') {
                    strExp[i] = str[i];
                    str[i] = ' ';
                    ++i;
                }

                --i;
            }
        }

        printf("%s\n%s\n", strExp.c_str(), str.c_str());
    }

    return 0;
}
