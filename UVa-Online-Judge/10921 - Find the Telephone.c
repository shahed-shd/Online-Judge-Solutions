/*==================================================
   Problem  :   10921 - Find the Telephone
   Run time :   0.000 sec.
   Language :   C
==================================================*/

#include <stdio.h>

int main()
{
    char str[35];
    char mapping[] = "22233344455566677778889999";
    int i;

    while(fgets(str, 35, stdin) != NULL) {
        for(i = 0; str[i]; ++i)
            if('A' <= str[i] && str[i] <= 'Z')
                str[i] = mapping[str[i] - 'A'];

        if(str[i-1] == '\n') str[i-1] = '\0';

        puts(str);
    }

    return 0;
}
