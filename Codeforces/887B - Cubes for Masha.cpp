// ==================================================
// Problem  :   887B - Cubes for Masha
// Run time :   0.030 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
using namespace std;

int n, a[3][6];
bool doesExist[999+3] = {false};
int values[3];

void fn(int idx)
{
    if(idx-1 == 0) doesExist[values[0]] = true;
    else if(idx-1 == 1) {
        doesExist[values[1]] = true;
        doesExist[values[0]*10 + values[1]] = true;
        doesExist[values[1]*10 + values[0]] = true;
    }
    else if(idx-1 == 2) {
        doesExist[values[2]] = true;
        doesExist[values[0]*10 + values[2]] = true;
        doesExist[values[2]*10 + values[0]] = true;
        doesExist[values[1]*10 + values[2]] = true;
        doesExist[values[2]*10 + values[1]] = true;
        doesExist[values[0]*100 + values[1]*10 + values[2]] = true;
        doesExist[values[0]*100 + values[2]*10 + values[1]] = true;
        doesExist[values[1]*100 + values[0]*10 + values[2]] = true;
        doesExist[values[1]*100 + values[2]*10 + values[0]] = true;
        doesExist[values[2]*100 + values[0]*10 + values[1]] = true;
        doesExist[values[2]*100 + values[1]*10 + values[0]] = true;
    }

    if(idx == n) return;

    for(int i = 0; i < 6; ++i) {
        values[idx] = a[idx][i];
        fn(idx+1);
    }
}

int main()
{
    //freopen("in.txt", "r", stdin);

    scanf("%d", &n);

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < 6; ++j)
            scanf("%d", &a[i][j]);

    fn(0);

    int ans = 0;

    for(int i = 1; i <= 1000; ++i) {
        if(!doesExist[i]) {
            ans = i - 1;
            break;
        }
    }

    printf("%d\n", ans);

    return 0;
}
