// ==================================================
// Problem  :   11831 - Sticker Collector Robot
// Run time :   0.000 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
using namespace std;


const int MAXN = 100 + 3;
const int MAXS = 5e4 + 3;


enum orientation {NORTH = 0, EAST, SOUTH, WEST};
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

int n, m;
char grid[MAXN][MAXN];


class Robot {
    int curr_pos_r, curr_pos_c;
    orientation ori;
    int stickerCount;

public:
    Robot(int r, int c, orientation ori) {
        curr_pos_r = r, curr_pos_c = c;
        this->ori = ori;
        stickerCount = 0;
    }

    void command_D()
    {
        ori = orientation((ori + 1) % 4);
    }

    void command_E()
    {
        ori = orientation((ori - 1 + 4) % 4);
    }

    void command_F()
    {
        int r = curr_pos_r + dr[ori];
        int c = curr_pos_c + dc[ori];

        if(0 <= r and r < n and 0 <= c and c < m and grid[r][c] != '#') {
            curr_pos_r = r, curr_pos_c = c;

            if(grid[r][c] == '*') {
                grid[r][c] = '.';
                ++stickerCount;
            }
        }
    }

    void command(char cmd)
    {
        if(cmd == 'D') command_D();
        else if (cmd == 'E') command_E();
        else if(cmd == 'F') command_F();
    }

    int total_sticker_collected() {
        return stickerCount;
    }
};


int main()
{
    //freopen("in.txt", "r", stdin);

    int s;

    while(scanf("%d %d %d\n", &n, &m, &s), n or m or s) {
        int init_r = -1, init_c;
        orientation init_ori;

        for(int i = 0; i < n; ++i) {
            scanf("%s", &grid[i][0]);

            if(init_r == -1) {
                for(int j = 0; j < m; ++j) {
                    if(grid[i][j] == 'N')
                        init_r = i, init_c = j, init_ori = NORTH;
                    else if(grid[i][j] == 'S')
                        init_r = i, init_c = j, init_ori = SOUTH;
                    else if(grid[i][j] == 'L')
                        init_r = i, init_c = j, init_ori = EAST;
                    else if(grid[i][j] == 'O')
                        init_r = i, init_c = j, init_ori = WEST;
                }
            }
        }

        char command_seq[MAXS];

        scanf("%s", command_seq);

        Robot rob(init_r, init_c, init_ori);

        for(int i = 0; i < s; ++i)
            rob.command(command_seq[i]);

        printf("%d\n", rob.total_sticker_collected());
    }

    return 0;
}
