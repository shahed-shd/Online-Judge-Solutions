#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int MAXL = 20;

char a[MAXL+3], b[MAXL+3];
short len_a, len_b;
short dp[MAXL+3][MAXL+3];

short fn(short i1, short i2)
{
    if(i1 == len_a || i2 == len_b)
        return abs(len_a+i2-i1 - len_b);

    if(dp[i1][i2] != -1) return dp[i1][i2];

    short mn;

    if(a[i1] == b[i2]) mn = fn(i1+1, i2+1);
    else mn = 1 + min(fn(i1, i2+1), min(fn(i1+1, i2), fn(i1+1, i2+1))); // INS, DEL, REP.

    return dp[i1][i2] = mn;
}

void printSol(int i1, int i2)
{
    if(i1 == len_a || i2 == len_b) {
        short newLen_a = len_a + i2 - i1;

        if(newLen_a <= i2) {
            for(int i = newLen_a; i < len_b; ++i)
                printf("I%c%02d", b[i], i+1);
        }
        else if(newLen_a > i2){
            for(int i = i2; i < newLen_a; ++i)
                printf("D%c%02d", a[i1++], i2+1);
        }

        return;
    }

    if(a[i1] == b[i2])
        printSol(i1+1, i2+1);
    else {
        short ins = fn(i1, i2+1), del = fn(i1+1, i2), rep = fn(i1+1, i2+1);
        short mn = min(ins, min(del, rep));

        if(mn == ins) {
            printf("I%c%02d", b[i2], i1+1+i2-i1);
            printSol(i1, i2+1);
        }
        else if(mn == del) {
            printf("D%c%02d", a[i1], i1+1+i2-i1);
            printSol(i1+1, i2);
        }
        else {
            printf("C%c%02d", b[i2], i1+1+i2-i1);
            printSol(i1+1, i2+1);
        }
    }
}

int main()
{
    //freopen("in", "r", stdin);

    while(scanf("%s", a), a[0] != '#') {
        scanf("%s", b);

        len_a = strlen(a), len_b = strlen(b);

        fill(&dp[0][0], &dp[MAXL+3][0], -1);

        fn(0, 0);
        printSol(0, 0);
        puts("E");
    }

    return 0;
}
