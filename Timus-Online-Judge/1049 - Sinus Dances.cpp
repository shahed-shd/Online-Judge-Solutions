#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

char str[200*6 + 200 + 100];

void hold_An(int n)
{
    int i, len;
    char num[4];

    str[0] = '\0';

    for(i = 1; i <= n; i++) {
        strcat(str, "sin(");

        sprintf(num, "%d", i);
        strcat(str, num);

        if(i & 1) strcat(str, "-");
        else strcat(str, "+");
    }

    len = strlen(str) - 1;
    for(i = 0; i < n; i++)
        str[len+i] = ')';

    str[len+i] = '\0';
}

int main()
{
    int n, i;
    cin >> n;

    for(i = 0; i < n-1; i++) cout << '(';

    for(i = n; i > 1; i--) {
        hold_An(n - i + 1);
        cout << str << '+' << i << ')';
    }
    hold_An(n - i + 1);
    cout << str << '+' << i << '\n';

    return 0;
}
