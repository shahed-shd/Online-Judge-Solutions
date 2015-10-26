#include <cstdio>
#include <algorithm>
using namespace std;

#define     prefer(i,j)     (*(prefer+n*i+j))

int *prefer;
int *wPartner;
int n;

bool isMorePreferable(int w, int m, int m1)
{
    w += n;
    for(int i = 0; i < n; ++i) {
        if(prefer(w,i) == m) return true;
        if(prefer(w,i) == m1) return false;
    }
    return false;
}

void stableMarriage()
{
    fill(wPartner, wPartner+n, -1);
    int mFree[n];
    fill(mFree, mFree+n, true);
    int freeCount = n;

    while(freeCount) {
        int m;
        for(m = 0; m < n && !mFree[m]; ++m);

        for(int i = 0; i < n && mFree[m]; ++i) {
            int w = prefer(m,i);

            if(wPartner[w] == -1) {
                wPartner[w] = m;
                mFree[m] = false;
                --freeCount;
            }
            else {
                int m1 = wPartner[w];

                if(isMorePreferable(w, m, m1)) {
                    wPartner[w] = m;
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

    int t;
    scanf("%d", &t);

    while(t--) {
        scanf("%d", &n);

        prefer = new int [2*n*n];

        int temp;

        for(int i = n; i < 2*n; ++i) {
            scanf("%*d");
            for(int j = 0; j < n; ++j) {
                scanf("%d", &temp);
                prefer(i,j) = temp - 1;
            }
        }

        for(int i = 0; i < n; ++i) {
            scanf("%*d");
            for(int j = 0; j < n; ++j) {
                scanf("%d", &temp);
                prefer(i,j) = temp - 1;
            }
        }

        wPartner = new int [n];

        stableMarriage();

        for(int i = 0; i < n; ++i)
            printf("%d %d\n", wPartner[i]+1, i+1);

        delete [] prefer;
        delete [] wPartner;
    }

    return 0;
}
