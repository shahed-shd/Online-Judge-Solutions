#include <cstdio>
using namespace std;

int main()
{
    int statement;

    while(scanf("%d\n", &statement) != EOF) {
        char str[10];
        int x = 0, sz = sizeof(str);

        while(statement--) {
            fgets(str, sz, stdin);
            (str[1] == '+')? ++x : --x;
        }

        printf("%d\n", x);
    }

    return 0;
}
