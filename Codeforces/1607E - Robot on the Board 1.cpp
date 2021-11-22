// ==================================================
// Problem  :   1607E - Robot on the Board 1
// Run time :   0.031 sec
// Language :   C++17
// ==================================================


#include <cstdio>
#include <algorithm>
using namespace std;


const int MAXS = 1e6 + 3;

char commands[MAXS];


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int t;
    scanf("%d", &t);

    while(t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        scanf("%s", commands);

        int topReached, bottomReached, leftReached, rightReached, startRow, startCol, currRow, currCol;
        topReached = bottomReached = leftReached = rightReached = startRow = startCol = currRow = currCol = 1;

        for(int i = 0; commands[i]; ++i) {
            char cmd = commands[i];

            if(cmd == 'L') {
                --currCol;
                if(currCol < 1) {
                    ++currCol;
                    ++rightReached;
                    if(m < rightReached) break;
                    ++startCol;
                } else {
                    leftReached = min(leftReached, currCol);
                }
            } else if(cmd == 'R') {
                ++currCol;
                if(m < currCol) {
                    --currCol;
                    --leftReached;
                    if(leftReached < 1) break;
                    --startCol;
                } else {
                    rightReached = max(rightReached, currCol);
                }
            } else if(cmd == 'D') {
                ++currRow;
                if(n < currRow) {
                    --currRow;
                    --topReached;
                    if(topReached < 1) break;
                    --startRow;
                } else {
                    bottomReached = max(bottomReached, currRow);
                }
            } else {
                --currRow;
                if(currRow < 1) {
                    ++currRow;
                    ++bottomReached;
                    if(n < bottomReached) break;
                    ++startRow;
                } else {
                    topReached = min(topReached, currRow);
                }
            }
        }

        printf("%d %d\n", startRow, startCol);
    }

    return 0;
}
