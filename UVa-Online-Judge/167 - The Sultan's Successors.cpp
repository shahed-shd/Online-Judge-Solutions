#include <iostream>
#include <bitset>
#include <iomanip>
using namespace std;

short numbers_in_board[8][8];
int sum, highest_sum;

bitset<8> board[8];
bitset<8> mark_row;
bitset<15> mark_diag1;
bitset<15> mark_diag2;

void place_queen(int col)
{
    if(col == 8) {
        highest_sum = max(highest_sum, sum);
        return;
    }

    for(int i = 0; i < 8; ++i) {
        if(mark_row[i] == 0 && mark_diag1[i+col] == 0 && mark_diag2[i+7-col] == 0) {
            mark_row[i] = mark_diag1[i+col] = mark_diag2[i+7-col] = true;
            sum += numbers_in_board[i][col];

            place_queen(col+1);

            mark_row[i] = mark_diag1[i+col] = mark_diag2[i+7-col] = false;
            sum -= numbers_in_board[i][col];
        }
    }

}

int main()
{
    int k;

    cin >> k;

    while(k--) {
        for(int i = 0; i < 8; ++i) {
            for(int j = 0; j < 8; ++j) {
                cin >> numbers_in_board[i][j];
            }
        }

        for(int i = 0; i < 8; ++i) board[i].reset();
        mark_row.reset();
        mark_diag1.reset();
        mark_diag2.reset();
        sum = highest_sum = 0;

        place_queen(0);

        cout.setf(ios::right);
        cout << setw(5) << highest_sum << '\n';
    }

    return 0;
}
