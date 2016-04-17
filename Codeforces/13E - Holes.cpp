#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

typedef     pair<int,int>   ii;

vector<int> powerOfHole;

class sqrtDecomposition {
    int numOfHole;
    int bucketSize;

    vector<int> nextHole;
    vector<int> jumpCnt;    // jump count to go to the next bucket.
    vector<int> ending;

public:
    sqrtDecomposition(int n) {
        numOfHole = n;
        bucketSize = sqrt(n);

        nextHole.resize(n+1);
        jumpCnt.resize(n+1);
        ending.resize(n+1);

        for(int i = n; i > 0; --i)
            update(i, powerOfHole[i]);
    }

    void update(int n, int val) {
        powerOfHole[n] = val;
        int start = (n/bucketSize) * bucketSize;

        for(int i = n; i >= start; --i) {
            int nxt = i + powerOfHole[i];

            if(nxt <= numOfHole) {
                if(nxt/bucketSize == i/bucketSize) {
                    nextHole[i] = nextHole[nxt];
                    jumpCnt[i] = 1 + jumpCnt[nxt];
                    ending[i] = ending[nxt];
                }
                else {
                    nextHole[i] = nxt;
                    jumpCnt[i] = 1;
                    ending[i] = ending[nxt];
                }
            }
            else {
                nextHole[i] = nxt;
                jumpCnt[i] = 1;
                ending[i] = i;
            }
        }
    }

    void query(int n) {
        int cnt = 0;

        while(nextHole[n] <= numOfHole) {
            cnt += jumpCnt[n];
            n = nextHole[n];
        }

        cnt += jumpCnt[n];

        printf("%d %d\n", ending[n], cnt);
    }
};

int main()
{
    //freopen("in", "r", stdin);

    int n, m;
    while(scanf("%d %d", &n, &m) != EOF) {
        powerOfHole.resize(n+1);

        int tmp;

        for(int i = 1; i <= n; ++i) {
            scanf("%d", &tmp);
            powerOfHole[i] = tmp;
        }

        sqrtDecomposition ob(n);

        while(m--) {
            int type;
            scanf("%d", &type);

            if(type) {
                scanf("%d", &tmp);
                ob.query(tmp);
            }
            else {
                int hole;
                scanf("%d %d", &hole, &tmp);
                ob.update(hole, tmp);
            }
        }
    }

    return 0;
}
