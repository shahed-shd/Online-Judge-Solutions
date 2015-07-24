#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>
using namespace std;

vector <short> temp;
char board[8][8];
int cnt;

void block_taken_squares(int row, int col);
void unblock_taken_squares(int row, int col);
void get_solutions(int row, int col);
void check(int c);    // recursive  approach.

int main()
{
    int tc;

    cin >> tc;

    while(tc--) {
        int row, col;

        cin >> row >> col;

        --row;
        --col;

        memset(board, 0, sizeof(board));
        cnt = 0;

        cout << "SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n";
        get_solutions(row, col);

        if(tc) cout << '\n';
    }

    return 0;
}


void block_taken_squares(int row, int col)
{
    int i, j;

    for(i = 0; i < 8; ++i) ++board[row][i];    // blocking horizontally.
    for(i = 0; i < 8; ++i) ++board[i][col];    // blocking vertically.
    --board[row][col];

    // Now, blocking diagonally.
    for(i = row-1, j = col-1; i >= 0 && j >= 0; --i, --j) ++board[i][j];
    for(i = row+1, j = col+1; i < 8 && j < 8; ++i, ++j) ++board[i][j];

    for(i = row-1, j = col+1; i >= 0 && j < 8 ; --i, ++j) ++board[i][j];
    for(i = row+1, j = col-1; i < 8 && j >= 0; ++i, --j) ++board[i][j];
}

void unblock_taken_squares(int row, int col)
{
    int i, j;

    for(i = 0; i < 8; ++i) --board[row][i];    // Unblocking horizontally.
    for(i = 0; i < 8; ++i) --board[i][col];    // Unblocking vertically.
    ++board[row][col];

    // Now, Unblocking diagonally.
    for(i = row-1, j = col-1; i >= 0 && j >= 0; --i, --j) --board[i][j];
    for(i = row+1, j = col+1; i < 8 && j < 8; ++i, ++j) --board[i][j];

    for(i = row-1, j = col+1; i >= 0 && j < 8 ; --i, ++j) --board[i][j];
    for(i = row+1, j = col-1; i < 8 && j >= 0; ++i, --j) --board[i][j];
}

void get_solutions(int row, int col)
{
    block_taken_squares(row, col);
    --board[row][col];

    for(int i = 0; i < 8; ++i) {
        if(board[i][0] == 0) {
            temp.push_back(i+1);
            block_taken_squares(i, 0);

            check(1);

            unblock_taken_squares(i, 0);
            temp.pop_back();
        }
    }
}

void check(int c)
{
    if(c == 8) {
        if(temp.size() == 8) {
            cout << setw(2) << ++cnt << "     ";
            for(int i = 0; i < 8; ++i) cout << ' ' << temp[i];
            cout << '\n';
        }

        return;
    }

    for(int i = 0; i < 8; ++i) {
        if(board[i][c] == 0) {
            temp.push_back(i+1);
            block_taken_squares(i, c);

            check(c+1);

            temp.pop_back();
            unblock_taken_squares(i, c);
        }
    }

    return;
}
