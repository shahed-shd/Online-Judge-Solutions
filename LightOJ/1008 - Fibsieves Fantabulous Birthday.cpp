#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long int t, caseno, s, i, r, c;

    cin >> t;
    caseno = 0;

    while(t--) {
        cin >> s;

        i = ceil(sqrt(s));

        if(i & 1) {                         //when i is odd.
            if((i*i -s) < i) {
                r = i;
                c = i*i - s + 1;
            }
            else {
                r = i - ((i*i - s) - (i-1));
                //r = s - (i-1) * (i-1);
                c = i;
            }
        }
        else {                               //when i is even.
            if((i*i -s) < i) {
                r = i*i - s + 1;
                c = i;
            }
            else {
                r = i;
                c = i - ((i*i - s) - (i-1));
                //c = s - (i-1)*(i-1);
            }
        }

        cout << "Case " << ++caseno << ": " <<  c << ' ' << r << '\n';
    }

    return 0;
}

/*

//At first, I wrote this program by class which is very interesting to me.
//The object will run forward according to the condition.
//Though its output is correct, bt 'Time Limit Exceeded' is encountered
//because of calculating by increment.


#include <iostream>
using namespace std;

class light {
    long long int width, height;
    char direction; //u, l, r, d respectively up, left, right, down.
public:
    long long int x, y;

    light() { x = 1, y = 1; width = height = 3; direction = 'u'; }
    void set_again() { x = 1, y = 1; width = height = 3; direction = 'u'; }
    light operator++() {
            if(x == 1 && y == 1) { y++; return *this; }
            if(x == 1 && y == 2) { x++; return *this; }
            if(x == 2 && y == 2) { y--; return *this; }
            if(x == 2 && y == 1) { x++; return *this; }

            switch (direction) {
                case 'u':
                    if(y < height) y++;
                    else if(y == height) {
                        x--;
                        direction = 'l';
                    }
                    break;
                case 'l':
                    if(x > 1) x--;
                    else if(x == 1) {
                        y++;
                        direction = 'r';
                        width++;
                        height++;
                    }
                    break;
                case 'r':
                    if(x < width) x++;
                    else if(x == width) {
                        y--;
                        direction = 'd';
                    }
                    break;
                case 'd':
                    if(y > 1) y--;
                    else if(y == 1) {
                        x++;
                        direction = 'u';
                        width++;
                        height++;
                    }
            }

            return *this;
        }
};

int main()
{
    light ob;
    long long int t, s, caseno, i;

    cin >> t;
    caseno = 0;

    while(t--) {
        cin >> s;

        for(i = 1; i < s; i++) ++ob;

        cout << "Case " << ++caseno << ": " << ob.x << ' ' << ob.y << '\n';

        ob.set_again();
    }

    return 0;
}
*/
