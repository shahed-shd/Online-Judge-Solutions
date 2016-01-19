// Reading and printing one character at a time is slow, and this problem has a big input.
// So, read the whole line once, manipulate the string and then print it all once as well.

// Run time: 0.003 sec

#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    char str[1000];

    while(fgets(str, sizeof(str), stdin) != NULL) {
        int len = strlen(str) - 1;

        for(int i = 0; i < len; ++i) str[i] -= 7;

        if(str[len] != '\n') str[len] -= 7;

        printf("%s", str);
    }

    return 0;
}


// ----------------- Alternatively -----------------
// Run time: 0.006 sec
/*

#include <cstdio>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int ch;     // taking this variable as 'char' gives WA.

    while(ch = getchar(), ch != EOF)
        (32 < ch)? putchar(ch-7) : putchar(ch);

    return 0;
}

*/
