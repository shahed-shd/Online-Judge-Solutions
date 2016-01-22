#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

#define     table(i, j)     (*(table+col*i+j))
bool *table;
int row, col, p;

void BtoD(int rs, int re, int cs, int ce)
{
    if(rs == re || cs == ce) return;

    int oneCnt = 0;

    for(int i = rs; i < re; ++i)
        for(int j = cs; j < ce; ++j)
           oneCnt += table(i, j);

    if(p && p % 50 == 0) putchar('\n');     // Each line contains maximum 50 characters.
    ++p;

    if(oneCnt == (re-rs)*(ce-cs))
        putchar('1');
    else if(oneCnt == 0)
        putchar('0');
    else {
        putchar('D');

        int rHalf = (rs + re + 1) >> 1;     // (re + rs + 1) / 2
        int cHalf = (cs + ce + 1) >> 1;

        BtoD(rs, rHalf, cs, cHalf);
        BtoD(rs, rHalf, cHalf, ce);
        BtoD(rHalf, re, cs, cHalf);
        BtoD(rHalf, re, cHalf, ce);
    }
}

void DtoB(int rs, int re, int cs, int ce)
{
    if(rs == re || cs == ce) return;

    char ch = getchar();

    if(ch == '0' || ch == '1') {
        for(int i = rs; i < re; ++i)
            for(int j = cs; j < ce; ++j)
                table(i, j) = ch - '0';
    }
    else {
        int rHalf = (rs + re + 1) >> 1;     // (re + rs + 1) / 2
        int cHalf = (cs + ce + 1) >> 1;

        DtoB(rs, rHalf, cs, cHalf);
        DtoB(rs, rHalf, cHalf, ce);
        DtoB(rHalf, re, cs, cHalf);
        DtoB(rHalf, re, cHalf, ce);
    }
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    char type;

    while(type = getchar(), type != '#') {
        char cstr[55];
        string str;

        scanf("%d %d\n", &row, &col);

        printf("%c%4d%4d\n", (type=='B')?'D':'B', row, col);

        table = new bool [row*col];

        if(type == 'B') {
            while(int(str.length()) < row * col) {
                scanf("%s\n", cstr);
                str += cstr;
            }

            int idx = 0;

            for(int i = 0; i < row; ++i)
                for(int j = 0; j < col; ++j)
                    table(i, j) = str[idx++] - '0';

            p = 0;
            BtoD(0, row, 0, col);
            putchar('\n');
        }
        else {
            DtoB(0, row, 0, col);
            getchar();

            int sz = row * col;

            for(int i = 0; i < sz; ++i) {
                if(i && i % 50 == 0) putchar('\n');
                putchar(*(table+i) + '0');
            }
            putchar('\n');
        }

        delete [] table;
    }

    return 0;
}
