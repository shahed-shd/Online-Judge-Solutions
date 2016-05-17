#include <cstdio>
using namespace std;

char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char str[100];
int n, L, curr;

bool isValid(int len)
{
    int len_half = len / 2;

    for(int patternLen = 1; patternLen <= len_half; ++patternLen) {
        bool flag = false;

        for(int i = 0; i < patternLen; ++i) {
            if(str[len-1-i] != str[len-1-i-patternLen]) {
                flag = true;
                break;
            }
        }

        if(!flag) return false;
    }

    return true;
}

bool fn(int len)
{
    if(!isValid(len)) return false;

    if(curr == n) {
        for(int i = 0; i < len; ++i) {
            if(i && i % 4 == 0)
                putchar((i % 64 == 0)? '\n' : ' ');

            putchar(str[i]);
        }

        printf("\n%d\n", len);

        return true;
    }

    ++curr;

    for(int i = 0; i < L; ++i) {
        str[len] = letters[i];
        if(fn(len+1)) return true;
    }

    return false;
}

int main()
{
    while(scanf("%d %d", &n, &L), n || L) {
        curr = 0;
        fn(0);
    }

    return 0;
}
