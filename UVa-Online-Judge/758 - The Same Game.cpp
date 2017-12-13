// ==================================================
// Problem  :   758 - The Same Game
// Run time :   0.020 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
using namespace std;


const int MAXR = 10;
const int MAXC = 15;

const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};


class Board {
    char grid[MAXR+3][MAXC+3];
    int tot_balls, moveCnt;
    int cluster_ids[MAXR+3][MAXC+3];


    int flood_fill(int r, int c, char color, int curr_id) {
        if(r < 1 or r > MAXR or c < 1 or c > MAXC or grid[r][c] != color or cluster_ids[r][c]) {
            return 0;
        }

        cluster_ids[r][c] = curr_id;
        int ret = 1;

        for(int i = 0; i < 4; ++i)
            ret += flood_fill(r+dr[i], c+dc[i], color, curr_id);

        return ret;
    }


    void get_largest_cluster(int &cluster_id, int &cluster_size, int &rr, int &cc) {
        fill(&cluster_ids[0][0], &cluster_ids[MAXR+1][0], 0);

        cluster_id = 0, cluster_size = 1;
        int curr_id = 0;

        for(int c = 1; c <= MAXC; ++c) {
            for(int r = 1; r <= MAXR; ++r) {
                char grid_rc = grid[r][c];

                if(cluster_ids[r][c] == 0 and (grid_rc == 'R' or grid_rc == 'G' or grid_rc == 'B')) {
                    int cnt = flood_fill(r, c, grid_rc, ++curr_id);

                    if(cnt > cluster_size) {
                        cluster_size = cnt;
                        cluster_id = curr_id;
                        rr = r, cc = c;
                    }
                }
            }
        }
    }


    void remove_cluster(int cluster_id, int cluster_size) {
        tot_balls -= cluster_size;

        // adjust rows.

        for(int c = 1; c <= MAXC; ++c) {
            int rr = 1;

            for(int r = 1; r <= MAXR; ++r) {
                if(cluster_ids[r][c] and cluster_ids[r][c] != cluster_id) {
                    if(r != rr) {
                        grid[rr][c] = grid[r][c];
                        cluster_ids[rr][c] = cluster_ids[r][c];
                    }
                    ++rr;
                }
            }

            for( ; rr <= MAXR; ++rr) {
                grid[rr][c] = ' ';
                cluster_ids[rr][c] = 0;
            }
        }

        // Now, adjust columns.

        int cc = 1;

        for(int c = 1; c <= MAXC; ++c) {
            if(grid[1][c] != ' ') {
                if(c != cc) {
                    for(int r = 1; r <= MAXR; ++r) {
                        grid[r][cc] = grid[r][c];
                        cluster_ids[r][cc] = grid[r][c];
                    }
                }
                ++cc;
            }
        }

        for( ; cc <= MAXC; ++cc)
            if(grid[1][cc] != ' ')
                for(int r = 1; r <= MAXR; ++r)
                    grid[r][cc] = ' ', cluster_ids[r][cc] = 0;
    }


public:
    Board() {
        for(int i = MAXR; i > 0; --i)
            scanf("%s", &grid[i][1]);

        tot_balls = MAXR * MAXC;
        moveCnt = 0;
    }


    void turn() {
        int cluster_id, cluster_size, r, c;
        int tot_score = 0;


        while(true) {
            get_largest_cluster(cluster_id, cluster_size, r, c);

            if(cluster_size < 2) break;

            int score = (cluster_size - 2) * (cluster_size - 2);
            printf("Move %d at (%d,%d): removed %d balls of color %c, got %d points.\n", ++moveCnt, r, c, cluster_size, grid[r][c], score);
            tot_score += score;

            remove_cluster(cluster_id, cluster_size);
        }

        tot_score += (tot_balls)? 0 : 1000;

        printf("Final score: %d, with %d balls remaining.\n", tot_score, tot_balls);
    }
};

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        printf("Game %d:\n\n", tc);

        Board b;
        b.turn();

        if(tc < t) putchar('\n');
    }

    return 0;
}
