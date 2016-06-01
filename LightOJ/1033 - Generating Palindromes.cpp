#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXL = 100+3;

int lcs(char str[], int len)    // Returns the length of LCS between str & reverse of str.
{
    int mat[MAXL][MAXL] = {{0}};

    for(int i = len-1; i >= 0; --i)
        for(int j = len-1; j >= 0; --j)
            mat[i][j] = (str[i] == str[len-1-j])? 1 + mat[i+1][j+1] : max(mat[i+1][j], mat[i][j+1]);

    return mat[0][0];
}

int main()
{
    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        char str[MAXL];
        scanf("%s", str);

        int len = strlen(str);

        printf("Case %d: %d\n", tc, len - lcs(str, len));
    }

    return 0;
}
