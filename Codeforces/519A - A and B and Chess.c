// ==================================================
// Problem  :   519A - A and B and Chess
// Run time :   0.015 sec.
// Language :   C11
// ==================================================

#include <stdio.h>

int weight(char ch)
{
    if(ch == 'Q' || ch == 'q') return 9;
    else if(ch == 'R' || ch == 'r') return 5;
    else if(ch == 'B' || ch == 'b') return 3;
    else if(ch == 'N' || ch == 'n') return 3;
    else if(ch == 'P' || ch == 'p') return 1;
    else return 0;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    char ch;
    int A[2] = {0, 0};

    while(ch = getchar(), ~ch)
        A['a' <= ch && ch <= 'z'] += weight(ch);

    if(A[0] < A[1]) puts("Black");
    else if(A[0] > A[1]) puts("White");
    else puts("Draw");

    return 0;
}
