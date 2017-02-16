// ==================================================
// Problem  :   Super Reduced String
// Score    :   10 /10
// Language :   C
// ==================================================

#include <stdio.h>

const int MAXL = 100 + 3;

int main()
{
    //freopen("in.txt", "r", stdin);

    char str[MAXL];
    int idx;
    char flag = 1;

    scanf("%s", str);

    while(flag){
        flag = 0;
        idx = 0;

        for(int i = 0; str[i]; ++i) {
            if(str[i] == str[i+1]) {
                flag = 1;
                ++i;
            }
            else {
                str[idx++] = str[i];
            }
        }

        str[idx] = '\0';
    }

    puts(str[0] ? str : "Empty String");

    return 0;
}
