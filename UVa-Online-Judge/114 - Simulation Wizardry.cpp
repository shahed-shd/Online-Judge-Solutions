#include <cstdio>
#include <vector>
using namespace std;

typedef     pair<int, int>  ii;     // value, cost

const int next_direction[4] = {3, 0, 1, 2};

int grid[51][51] = {0};
int m, n, wall_cost;
vector<ii> bumpers;

class pinball {
    int x, y, dir, lifetime, point;

    void bumper_hit_at(int xx, int yy) {
        int b = grid[xx][yy] - 1;
        point += bumpers[b].first;
        lifetime -= bumpers[b].second;
        dir = next_direction[dir];
    }

public:
    pinball(int x, int y, int dir, int t) {
        this->x = x, this->y = y, this->dir = dir, lifetime = t, point = 0;
    }

    void bounce() {
        --lifetime;

        if(dir == 0) {                  // move right.
            if(grid[x+1][y])
                bumper_hit_at(x+1, y);
            else if(x+1 == m)
                dir = next_direction[dir], lifetime -= wall_cost;
            else ++x;
        }
        else if(dir == 1) {             // move up.
            if(grid[x][y+1])
                bumper_hit_at(x, y+1);
            else if(y+1 == n)
                dir = next_direction[dir], lifetime -= wall_cost;
            else ++y;
        }
        else if(dir == 2) {             // move left.
            if(grid[x-1][y])
                bumper_hit_at(x-1, y);
            else if(x-1 == 1)
                dir = next_direction[dir], lifetime -= wall_cost;
            else --x;
        }
        else if(dir == 3) {             // move down.
            if(grid[x][y-1])
                bumper_hit_at(x, y-1);
            else if(y-1 == 1)
                dir = next_direction[dir], lifetime -= wall_cost;
            else --y;
        }
    }

    int get_lifetime() { return lifetime; };

    int get_point() { return point; };
};


int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int b, x, y, val, cost;

    scanf("%d %d %d %d", &m, &n, &wall_cost, &b);

    for(int i = 1; i <= b; ++i) {
        scanf("%d %d %d %d", &x, &y, &val, &cost);
        grid[x][y] = i;
        bumpers.push_back(ii(val, cost));
    }

    int dir, lifetime, total_point = 0;

    while(scanf("%d %d %d %d", &x, &y, &dir, &lifetime) != EOF) {
        pinball ball(x, y, dir, lifetime);

        while(ball.get_lifetime() > 1)
            ball.bounce();

        printf("%d\n", ball.get_point());

        total_point += ball.get_point();
    }

    printf("%d\n", total_point);

    return 0;
}
