#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int rect_x, rect_y, x, y;

    cin >> rect_x >> rect_y;

    bool is_scent[rect_x+1][rect_y+1];
    memset(is_scent, 0, sizeof(is_scent));

    while(cin >> x >> y) {
        char orientation;
        string instructions;

        cin >> orientation >> instructions;

        int len = instructions.length();
        bool is_lost = false;

        for(int i = 0; i < len; ++i) {
            if(instructions[i] == 'L') {
                if(orientation == 'N') orientation = 'W';
                else if(orientation == 'E') orientation = 'N';
                else if(orientation == 'S') orientation = 'E';
                else if(orientation == 'W') orientation = 'S';
            }
            else if(instructions[i] == 'R') {
                if(orientation == 'N') orientation = 'E';
                else if(orientation == 'E') orientation = 'S';
                else if(orientation == 'S') orientation = 'W';
                else if(orientation == 'W') orientation = 'N';
            }
            else {      // when instructions[i] == 'F'
                if(orientation == 'N' && y == rect_y && is_scent[x][y] == false) {
                    is_lost = true;
                    is_scent[x][y] = true;
                    break;
                }
                else if(orientation == 'E' && x == rect_x && is_scent[x][y] == false) {
                    is_lost = true;
                    is_scent[x][y] = true;
                    break;
                }
                else if(orientation == 'S' && y == 0 && is_scent[x][y] == false) {
                    is_lost = true;
                    is_scent[x][y] = true;
                    break;
                }
                else if(orientation == 'W' && x == 0 && is_scent[x][y] == false) {
                    is_lost = true;
                    is_scent[x][y] = true;
                    break;
                }
                else if(orientation == 'N' && y == rect_y && is_scent[x][y] == true);   // do nothing.
                else if(orientation == 'E' && x == rect_x && is_scent[x][y] == true);   // do nothing.
                else if(orientation == 'S' && y == 0 && is_scent[x][y] == true);    // do nothing.
                else if(orientation == 'W' && x == 0 && is_scent[x][y] == true);    // do nothing.
                else {
                    if(orientation == 'N') ++y;
                    else if(orientation == 'E') ++x;
                    else if(orientation == 'S') --y;
                    else if(orientation == 'W') --x;
                }
            }
        }

        cout << x << ' ' << y << ' ' << orientation;
        if(is_lost) cout << " LOST\n";
        else cout << '\n';
    }

    return 0;
}
