// ==================================================
// Problem  :   10377 - Maze Traversal
// Run time :   0.000 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
using namespace std;


const int MAXR = 60 + 3;

enum direction {NORTH = 0, EAST, SOUTH, WEST};
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};


int row, col;
char grid[MAXR][MAXR];


class Robot {
    int curr_row, curr_col;
    direction dir;

public:

    Robot(int r, int c) {
        curr_row = r, curr_col = c;
        dir = NORTH;
    }

    void command_R() {
        dir = direction((dir + 1) % 4);
    }

    void command_L() {
        dir = direction((dir - 1 + 4) % 4);
    }

    void command_F() {
        int r = curr_row + dr[dir];
        int c = curr_col + dc[dir];

        if(r < 1 or row < r or c < 1 or col < c or grid[r][c] != ' ')
            return;

        curr_row = r, curr_col = c;
    }

    void show() {
        char d;

        if(dir == NORTH) d = 'N';
        else if(dir == EAST) d = 'E';
        else if(dir == SOUTH) d = 'S';
        else d = 'W';

        printf("%d %d %c\n", curr_row, curr_col, d);
    }
};


int main()
{
    //freopen("in.txt", "r", stdin);

    int t;
    scanf("%d", &t);

    while(t--) {
        scanf("%d %d\n", &row, &col);

        for(int i = 1; i <= row; ++i)
            scanf("%[^\n]\n", &grid[i][1]);

        int r, c;
        scanf("%d %d", &r, &c);

        Robot robot(r, c);
        char cmd;

        do {
            cmd = getchar();

            if(cmd == 'R') robot.command_R();
            else if(cmd == 'L') robot.command_L();
            else if(cmd == 'F') robot.command_F();
            else if(cmd == 'Q') robot.show();

        } while(cmd != 'Q');

        if(t) putchar('\n');
    }

    return 0;
}
