#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;

vector<string> maze;

const int8_t dr[] = {-1, 1, 0, 0};
const int8_t dc[] = {0, 0, -1, 1};

void flood_fill(int r, int c)
{
    //if(r < 0 || r >= int(maze.size()) || c < 0 || c >= int(maze[r].length())) return;
    // It's not necessary as there're rooms with boundary walls.

    if(maze[r][c] != ' ') return;

    maze[r][c] = '#';

    for(int8_t i = 0; i < 4; ++i)
        flood_fill(r+dr[i], c+dc[i]);
}

int main()
{
    ios::sync_with_stdio(false);

    int tc;
    cin >> tc;
    cin.ignore(1, '\n');

    while(tc--) {
        maze.clear();

        string str;
        int start_r = -1, start_c = -1;

        while(getline(cin, str), str.front() != '_') {
            maze.push_back(str);

            if(start_r == -1) {     // -1 indicates that the starting position isn't found.
                size_t sz = str.find('*');
                if(sz != string::npos)
                    start_r = maze.size()-1, start_c = sz;
            }
        }

        maze[start_r][start_c] = ' ';
        flood_fill(start_r, start_c);

        for(auto& s : maze)
            cout << s << '\n';

        cout << str << '\n';
    }

    return 0;
}



// ------------------ Alternatively ------------------
/*

#include <cstdio>
#include <cstdint>
using namespace std;

char maze[35][85];

const int8_t dr[] = {-1, 1, 0, 0};
const int8_t dc[] = {0, 0, -1, 1};

void flood_fill(int r, int c)
{
    if(maze[r][c] != ' ') return;

    maze[r][c] = '#';

    for(int8_t i = 0; i < 4; ++i)
        flood_fill(r+dr[i], c+dc[i]);
}

int main()
{
    //freopen("in", "r", stdin);

    int tc;
    scanf("%d", &tc);
    getchar();

    while(tc--) {
        char ch;
        int r = 0, c, start_r =0, start_c =0;

        while(ch = getchar(), ch != '_') {
            c = 0;
            maze[r][c] = ch;

            while(ch = getchar(), ch != '\n') {
                maze[r][++c] = ch;

                if(ch == '*')
                    start_r = r, start_c = c;
            }

            maze[r++][++c] = '\0';
        }

        c = 0;
        maze[r][c] = ch;

        while(ch = getchar(), ch != '\n')
            maze[r][++c] = ch;

        maze[r][++c] = '\0';

        // input complete.

        maze[start_r][start_c] = ' ';
        flood_fill(start_r, start_c);

        for(int i = 0; i <= r; ++i)
            puts(maze[i]);
    }

    return 0;
}

*/



// ------------------ Alternatively (with bfs)------------------

/*
#include <cstdio>
#include <cstdint>
#include <queue>
using namespace std;

typedef     pair<int,int>   ii;

char maze[35][85];

const int8_t dr[] = {-1, 1, 0, 0};
const int8_t dc[] = {0, 0, -1, 1};

void bfs(ii start)
{
    queue<ii> q;
    q.push(start);

    ii pr;
    int r, c;

    while(!q.empty()) {
        pr = q.front(); q.pop();

        for(int8_t i = 0; i < 4; ++i) {
            r = pr.first+dr[i], c = pr.second+dc[i];

            if(maze[r][c] == ' ') {
                maze[r][c] = '#';
                q.push(ii(r, c));
            }
        }
    }
}

int main()
{
    //freopen("in", "r", stdin);

    int tc;
    scanf("%d", &tc);
    getchar();

    while(tc--) {
        char ch;
        int r = 0, c, start_r =0, start_c =0;

        while(ch = getchar(), ch != '_') {
            c = 0;
            maze[r][c] = ch;

            while(ch = getchar(), ch != '\n') {
                maze[r][++c] = ch;

                if(ch == '*')
                    start_r = r, start_c = c;
            }

            maze[r++][++c] = '\0';
        }

        c = 0;
        maze[r][c] = ch;

        while(ch = getchar(), ch != '\n')
            maze[r][++c] = ch;

        maze[r][++c] = '\0';

        // input complete.

        maze[start_r][start_c] = ' ';
        bfs(ii(start_r, start_c));

        for(int i = 0; i <= r; ++i)
            puts(maze[i]);
    }

    return 0;
}

*/
