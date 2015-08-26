#include <iostream>
#include <queue>
using namespace std;

#define field(i,j) *(field+c*i+j)
#define level(i,j) *(level+c*i+j)

int r, c;
int *level;
bool *field;

void bfs(int r_start, int c_start, int r_dest, int c_dest)
{
    queue<pair<int,int> > q;
    pair<int,int> u;

    q.push(make_pair(r_start, c_start));
    field(r_start, c_start) = true;
    level(r_start, c_start) = 0;

    int x, y;
    int fx[] = {1, -1, 0, 0};
    int fy[] = {0, 0, 1, -1};

    while(!q.empty()) {
        u = q.front();

        for(short i = 0; i < 4; ++i) {
            x = u.first+fx[i];
            y = u.second+fy[i];

            if(0 <= x && x < r && 0 <= y && y < c && field(x,y) == false) {
                field(x,y) = true;
                level(x,y) = level(u.first, u.second) + 1;
                q.push(make_pair(x, y));
            }

            if(x == r_dest && y == c_dest) return;
        }

        q.pop();
    }
}

int main()
{
    while(cin >> r >> c, r != 0 || c != 0) {
        field = new bool [r*c];
        level = new int [r*c];
        for(int i = 0; i < r*c; ++i) {
            field[i] = false;
            level[i] = 0;
        }

        int rows, r_pos, c_pos, n;

        cin >> rows;

        while(rows--) {
            cin >> r_pos >> n;
            while(n--) {
                cin >> c_pos;
                field(r_pos, c_pos) = true;
            }
        }

        int r_start, c_start, r_dest, c_dest;

        cin >> r_start >> c_start >> r_dest >> c_dest;

        bfs(r_start, c_start, r_dest, c_dest);

        cout << level(r_dest, c_dest) << '\n';

        delete [] field;
        delete [] level;
    }

    return 0;
}
