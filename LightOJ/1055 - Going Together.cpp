// Run time: 0.044 sec.

#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

#define     ff      first
#define     ss      second

typedef     pair<short, short>       ii;

const int MAXN = 10+3;
const ii iiC(-1, -1);       // To be used in default argument only.

int n;
char grid[MAXN][MAXN];

class moveNode {
    ii r[3];

    void north(ii &x, ii occupied1 = iiC, ii occupied2 = iiC) {
        --x.ff;
        if(x.ff < 1 || grid[x.ff][x.ss] == '#' || x == occupied1 || x == occupied2) ++x.ff; // Can't move.
    }

    void south(ii &x, ii occupied1 = iiC, ii occupied2 = iiC) {
        ++x.ff;
        if(x.ff > n || grid[x.ff][x.ss] == '#' || x == occupied1 || x == occupied2) --x.ff;
    }

    void west(ii &x, ii occupied1 = iiC, ii occupied2 = iiC) {
        --x.ss;
        if(x.ss < 1 || grid[x.ff][x.ss] == '#' || x == occupied1 || x == occupied2) ++x.ss;
    }

    void east(ii &x, ii occupied1 = iiC, ii occupied2 = iiC) {
        ++x.ss;
        if(x.ss > n || grid[x.ff][x.ss] == '#' || x == occupied1 || x == occupied2) --x.ss;
    }

    inline bool is_serial_ff(int i1, int i2, int i3) { return (r[i1].ff <= r[i2].ff && r[i2].ff <= r[i3].ff); }
    inline bool is_serial_ss(int i1, int i2, int i3) { return (r[i1].ss <= r[i2].ss && r[i2].ss <= r[i3].ss); }

public:
    moveNode(ii &a, ii &b, ii &c) { r[0] = a, r[1] = b, r[2] = c; }

    void goNorth() {
        if(is_serial_ff(0, 1, 2)) north(r[0]), north(r[1], r[0]), north(r[2], r[0], r[1]);
        else if(is_serial_ff(0, 2, 1)) north(r[0]), north(r[2], r[0]), north(r[1], r[0], r[2]);
        else if(is_serial_ff(1, 0, 2)) north(r[1]), north(r[0], r[1]), north(r[2], r[1], r[0]);
        else if(is_serial_ff(1, 2, 0)) north(r[1]), north(r[2], r[1]), north(r[0], r[1], r[2]);
        else if(is_serial_ff(2, 0, 1)) north(r[2]), north(r[0], r[2]), north(r[1], r[2], r[0]);
        else if(is_serial_ff(2, 1, 0)) north(r[2]), north(r[1], r[2]), north(r[0], r[2], r[1]);
    }

    void goSouth() {
        if(is_serial_ff(0, 1, 2)) south(r[2]), south(r[1], r[2]), south(r[0], r[2], r[1]);
        else if(is_serial_ff(0, 2, 1)) south(r[1]), south(r[2], r[1]), south(r[0], r[1], r[2]);
        else if(is_serial_ff(1, 0, 2)) south(r[2]), south(r[0], r[2]), south(r[1], r[2], r[0]);
        else if(is_serial_ff(1, 2, 0)) south(r[0]), south(r[2], r[0]), south(r[1], r[0], r[2]);
        else if(is_serial_ff(2, 0, 1)) south(r[1]), south(r[0], r[1]), south(r[2], r[1], r[0]);
        else if(is_serial_ff(2, 1, 0)) south(r[0]), south(r[1], r[0]), south(r[2], r[0], r[1]);
    }

    void goWest() {
        if(is_serial_ss(0, 1, 2)) west(r[0]), west(r[1], r[0]), west(r[2], r[0], r[1]);
        else if(is_serial_ss(0, 2, 1)) west(r[0]), west(r[2], r[0]), west(r[1], r[0], r[2]);
        else if(is_serial_ss(1, 0, 2)) west(r[1]), west(r[0], r[1]), west(r[2], r[1], r[0]);
        else if(is_serial_ss(1, 2, 0)) west(r[1]), west(r[2], r[1]), west(r[0], r[1], r[2]);
        else if(is_serial_ss(2, 0, 1)) west(r[2]), west(r[0], r[2]), west(r[1], r[2], r[0]);
        else if(is_serial_ss(2, 1, 0)) west(r[2]), west(r[1], r[2]), west(r[0], r[2], r[1]);
    }

    void goEast() {
        if(is_serial_ss(0, 1, 2)) east(r[2]), east(r[1], r[2]), east(r[0], r[2], r[1]);
        else if(is_serial_ss(0, 2, 1)) east(r[1]), east(r[2], r[1]), east(r[0], r[1], r[2]);
        else if(is_serial_ss(1, 0, 2)) east(r[2]), east(r[0], r[2]), east(r[1], r[2], r[0]);
        else if(is_serial_ss(1, 2, 0)) east(r[0]), east(r[2], r[0]), east(r[1], r[0], r[2]);
        else if(is_serial_ss(2, 0, 1)) east(r[1]), east(r[0], r[1]), east(r[2], r[1], r[0]);
        else if(is_serial_ss(2, 1, 0)) east(r[0]), east(r[1], r[0]), east(r[2], r[0], r[1]);
    }

    inline bool isTarget() {
        return (grid[r[0].ff][r[0].ss] == 'X' && grid[r[1].ff][r[1].ss] == 'X' && grid[r[2].ff][r[2].ss] == 'X');
    }

    int hashing() {
        int ret = r[0].ff * 10 + r[0].ss;

        ret *= 100;
        ret += r[1].ff * 10 + r[1].ss;

        ret *= 100;
        ret += r[2].ff * 10 + r[2].ss;

        return ret;
    }
};


int bfs(ii a, ii b, ii c)
{
    queue<moveNode> q;
    short level[1000000] = {0};

    moveNode u(a, b, c);

    q.push(u);
    level[u.hashing()] = 1;

    while(!q.empty()) {
        u = q.front(); q.pop();
        short level_u = level[u.hashing()];

        if(u.isTarget()) return level_u-1;

        moveNode v = u;
        v.goNorth();
        int hash_v = v.hashing();
        if(!level[hash_v]) { level[hash_v] = level_u+1; q.push(v); }

        v = u;
        v.goSouth();
        hash_v = v.hashing();
        if(!level[hash_v]) { level[hash_v] = level_u+1; q.push(v); }

        v = u;
        v.goWest();
        hash_v = v.hashing();
        if(!level[hash_v]) { level[hash_v] = level_u+1; q.push(v); }

        v = u;
        v.goEast();
        hash_v = v.hashing();
        if(!level[hash_v]) { level[hash_v] = level_u+1; q.push(v); }
    }

    return -1;
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        scanf("%d", &n);

        ii a, b, c;

        for(int i = 1; i <= n; ++i) {
            scanf("%s", grid[i]+1);

            for(int j = 1; j <= n; ++j) {
                if(grid[i][j] == 'A') a = ii(i, j);
                else if(grid[i][j] == 'B') b = ii(i, j);
                else if(grid[i][j] == 'C') c = ii(i, j);
            }
        }

        int moves = bfs(a, b, c);

        printf("Case %d: ", tc);

        (moves == -1)? puts("trapped") : printf("%d\n", moves);
    }

    return 0;
}
