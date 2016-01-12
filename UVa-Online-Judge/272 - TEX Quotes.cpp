#include <cstdio>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    char ch;
    bool flag = true;

    while(ch = getchar(), ch != EOF) {
        if(ch == '"') {
            (flag)? printf("``") : printf("''");
            flag = !flag;
        }
        else putchar(ch);
    }

    return 0;
}
