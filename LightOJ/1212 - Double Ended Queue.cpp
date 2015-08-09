#include <iostream>
using namespace std;

class d_e_q {
    int *p;
    int q_size;
    int filled;
public:
    void set_q(int n) { q_size = n; filled = 0; p = new int [n]; }
    bool push_left(int x) {
            if(filled == q_size) return 0; //that means operation failed.
            else {
                for(int i = filled - 1; i >= 0; i--) {
                    p[i+1] = p[i];
                }
                p[0] = x;
                filled++;
                return 1; //that means operation done.
            }
        }
    bool push_right(int x) {
            if(filled == q_size) return 0;
            else {
                p[filled] = x;
                filled++;
                return 1;
            }
        }
    bool pop_left(int &x) {
            if(filled == 0) return 0;
            else {
                x = p[0];

                for(int i = 0; i < filled; i++)
                    p[i] = p[i+1];

                filled--;
                return 1;
            }
        }
    bool pop_right(int &x) {
            if(filled == 0) return 0;
            else {
                x = p[filled - 1];
                filled--;
                return 1;
            }
        }
    void clear_q() { delete [] p; }
};

struct answer {
    char operation;    //l, r, L, R, f, e means pushLeft, pushRight, popLeft, popRight, full, empty respectively.
    int x;
};

int main()
{
    int t, tc, n, m, x, i;
    d_e_q ob;
    answer *ans;
    char str[9];
    bool flag;

    cin >> t;
    tc = 0;

    while(t--) {
        cin >> n >> m;

        ob.set_q(n);
        ans = new answer [m];
        i = 0;

        for(i = 0; i < m; i++) {
            cin >> str;

            if(str[1] == 'u') {
                cin >> x;

                if(str[4] == 'L') {
                    flag = ob.push_left(x);
                    if(flag) { ans[i].operation = 'l'; ans[i].x = x; }
                    else ans[i].operation = 'f';
                }
                else {
                    flag = ob.push_right(x);
                    if(flag) {ans[i].operation = 'r'; ans[i].x = x; }
                    else ans[i].operation = 'f';
                }
            }
            else {
                if(str[3] == 'L') {
                    flag = ob.pop_left(x);
                    if(flag) { ans[i].operation = 'L'; ans[i].x = x; }
                    else ans[i].operation = 'e';
                }
                else {
                    flag = ob.pop_right(x);
                    if(flag) { ans[i].operation = 'R'; ans[i].x = x; }
                    else ans[i].operation = 'e';
                }
            }
        }

        cout << "Case " << ++tc << ":\n";

        for(i = 0; i < m; i++) {
            switch(ans[i].operation) {
                case 'l':
                    cout << "Pushed in left: " << ans[i].x << '\n';
                    break;
                case 'r':
                    cout << "Pushed in right: " << ans[i].x << '\n';
                    break;
                case 'L':
                    cout << "Popped from left: " << ans[i].x << '\n';
                    break;
                case 'R':
                    cout << "Popped from right: " << ans[i].x << '\n';
                    break;
                case 'f':
                    cout << "The queue is full\n";
                    break;
                case 'e':
                    cout << "The queue is empty\n";
                    break;
            }
        }

        ob.clear_q();
        delete [] ans;
    }

    return 0;
}
