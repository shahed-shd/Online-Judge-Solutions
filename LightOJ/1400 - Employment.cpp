#include <cstdio>
#include <algorithm>
using namespace std;

#define     prefer(i,j)     (*(prefer+n*i+j))

int n;
int *prefer;
int *wPartner;

bool isMorePreferable(int w, int m, int m1)
{
    for(int i = 0; i < n; ++i) {
        if(prefer(w,i) == m) return true;
        if(prefer(w,i) == m1) return false;
    }
    return true;
}

void gale_shapley()
{
    fill(wPartner, wPartner+n, -1);
    bool mFree[n];
    fill(mFree, mFree+n, true);
    int freeCount = n;

    while(freeCount > 0) {
        int m;
        for(m = 0; m < n; ++m)
            if(mFree[m]) break;

        for(int i = 0; i < n && mFree[m]; ++i) {
            int w = prefer(m,i);

            if(wPartner[w-n] == -1) {
                wPartner[w-n] = m;
                mFree[m] = false;
                --freeCount;
            }
            else {
                int m1 = wPartner[w-n];

                if(isMorePreferable(w, m, m1)) {
                    wPartner[w-n] = m;
                    mFree[m] = false;
                    mFree[m1] = true;
                }
            }
        }
    }
}

int main()
{
    //freopen("in", "r", stdin);

    int testCase;
    scanf("%d", &testCase);

    for(int tc = 1; tc <= testCase; ++tc) {
        scanf("%d", &n);

        prefer = new int [2*n*n];

        int temp;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                scanf("%d", &temp);
                prefer(i,j) = temp - 1;
            }
        }

        for(int i = n; i < 2*n; ++i) {
            for(int j = 0; j < n; ++j) {
                scanf("%d", &temp);
                prefer(i,j) = temp - 1;
            }
        }

        wPartner = new int [n];

        gale_shapley();

        printf("Case %d:", tc);

        for(int i = 0; i < n; ++i)
            printf(" (%d %d)", wPartner[i]+1, i+1+n);

        putchar('\n');

        delete [] prefer;
        delete [] wPartner;
    }

    return 0;
}
