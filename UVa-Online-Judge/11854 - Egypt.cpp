#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    bool flag;

    while(cin >> a >> b >> c, a != 0 || b != 0 || c != 0) {
        if(a*a + b*b == c*c) flag = true;
        
        else if(a*a + c*c == b*b) flag = true;
        
        else if(b*b + c*c == a*a) flag = true;
        
        else flag = false;

        if(flag) cout << "right\n";
        else cout << "wrong\n";
    }

    return 0;
}
