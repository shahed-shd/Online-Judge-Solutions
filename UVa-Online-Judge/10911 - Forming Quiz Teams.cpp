#include <cstdio>
#include <algorithm>
#include <bitset>
#include <cfloat>
#include <utility>
#include <vector>
#include <cmath>
using namespace std;

typedef     pair<int,int>   ii;

int n, totalStudent;
vector<ii> students;

double memo[1<<16];
bitset< 1<<16 > visited;

inline bool bitcheck(int n, int pos) { return (n>>pos) & 1; };
inline int biton(int n, int pos) { return n | (1<<pos); };

double fn(int mask)
{
    if(mask == (1<<totalStudent)-1) return 0;

    if(visited[mask]) return memo[mask];

    int idx, x, y;

    for(int i = 0; i < totalStudent; ++i) {
        if(!bitcheck(mask, i)) {
            idx = i;
            break;
        }
    }

    x = students[idx].first, y = students[idx].second;

    double &ret = memo[mask];
    ret = DBL_MAX;

    for(int i = 0; i < totalStudent; ++i)
        if(idx != i && !bitcheck(mask, i))
            ret = min(ret, hypot(x - students[i].first, y - students[i].second) + fn(biton(biton(mask, idx), i)));

    visited[mask] = true;
    return ret;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int tc = 0;

    while(scanf("%d", &n), n) {
        students.clear();

        totalStudent = n+n;
        int x, y;

        for(int i = 0; i < totalStudent; ++i) {
            scanf("%*s %d %d", &x, &y);
            students.emplace_back(x, y);
        }

        visited.reset();

        printf("Case %d: %.2f\n", ++tc, fn(0));
    }

    return 0;
}
