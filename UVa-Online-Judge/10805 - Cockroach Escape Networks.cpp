#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

#define     matrix(i,j)     (*(matrix+N*i+j))
const int INF = INT_MAX / 2;

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int n, m;
        scanf("%d %d", &n, &m);

        int N, splitNode, u, v, *matrix;

        N = n+m;
        splitNode = n;

        matrix = new int [N*N];
        fill_n(matrix, N*N, INF);
        for(int i = 0; i < N; ++i) matrix(i, i) = 0;

        while(m--) {
            scanf("%d %d", &u, &v);
            matrix(u, splitNode) = matrix(splitNode, v) = 1;
            matrix(v, splitNode) = matrix(splitNode, u) = 1;
            ++splitNode;
        }

        for(int k = 0; k < N; ++k)      // Floyd-Warshall algorithm.
            for(int i = 0; i < N; ++i)
                for(int j = 0; j < N; ++j)
                    if(matrix(i, j) > matrix(i, k) + matrix(k, j))
                        matrix(i, j) = matrix(i, k) + matrix(k, j);

        int ans = INF;

        for(int i = 0; i < N; ++i)
            ans = min(ans, *(max_element(&matrix(i, 0), &matrix(i, n))));

        printf("Case #%d:\n%d\n\n", tc, ans);

        delete [] matrix;
    }

    return 0;
}
