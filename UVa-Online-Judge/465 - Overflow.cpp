#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
using namespace std;

int main()
{
    double n1, n2;
    char sign;
    string expression;

    while(getline(cin, expression)) {
        cout << expression << '\n';

        sscanf((char*) expression.c_str(), "%lf %c %lf", &n1, &sign, &n2);

        if(n1 > INT_MAX) cout << "first number too big\n";

        if(n2 > INT_MAX) cout << "second number too big\n";

        if(sign == '+' && n1+n2 > INT_MAX) cout << "result too big\n";

        if(sign == '*' && n1*n2 > INT_MAX) cout << "result too big\n";
    }

    return 0;
}
