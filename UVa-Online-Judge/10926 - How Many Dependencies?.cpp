#include <cstdio>
#include <bitset>
#include <vector>
using namespace std;

const int MAXN = 100;

vector<bitset<MAXN> > mat;

int main()
{
    //freopen("in", "r", stdin);

    int n;

    while(scanf("%d", &n), n) {
        mat.clear();
        mat.resize(n);

        for(int i = 0; i < n; ++i) {
            int t, v;
            scanf("%d", &t);

            while(t--) {
                scanf("%d", &v);
                mat[i][--v] = true;
            }
        }

        for(int k = 0; k < n; ++k)      // Floyd-Warshall
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    if(mat[i][k] && mat[k][j])
                        mat[i][j] = true;

        int ans, mx = -1;

        for(int i = 0; i < n; ++i) {
            int cnt = mat[i].count();
            if(cnt > mx)
                mx = cnt, ans = i;
        }

        printf("%d\n", ans+1);
    }

    return 0;
}
