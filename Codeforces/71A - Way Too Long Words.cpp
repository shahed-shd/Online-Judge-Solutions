#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    while(n--) {
        char word[100+5];

        scanf("%s", word);

        int len = strlen(word);

        if(len > 10) printf("%c%d%c\n", word[0], len-2, word[len-1]);
        else puts(word);
    }

    return 0;
}
