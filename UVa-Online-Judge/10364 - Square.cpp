#include <cstdio>
#include <algorithm>
#include <bitset>
using namespace std;

const int MAXN = 20;

int n, arr[MAXN];
int targetValue;
bitset<(1<<MAXN)> visited;

inline bool bitcheck(int n, int pos) { return (n>>pos) & 1; }
inline int biton(int n, int pos) { return n | (1<<pos); }

bool fn(int mask, int lenSum)
{
    if(lenSum == targetValue) {
        if(mask == (1<<n)-1) return true;
        return fn(mask, 0);
    }

    if(visited[mask]) return false;

    for(int i = 0; i < n; ++i)
        if(!bitcheck(mask, i) && lenSum+arr[i] <= targetValue)
            if(fn(biton(mask, i), lenSum+arr[i]))
                return true;

    visited[mask] = true;

    return false;
}

int main()
{
    //freopen("in", "r", stdin);

    int tc;
    scanf("%d", &tc);

    while(tc--) {
        scanf("%d", &n);

        int sum = 0;

        for(int i = 0; i < n; ++i) {
            scanf("%d", arr+i);
            sum += arr[i];
        }

        if(sum % 4) {
            puts("no");
            continue;
        }

        targetValue = sum / 4;

        visited.reset();

        puts((fn(0, 0))? "yes" : "no");
    }

    return 0;
}
