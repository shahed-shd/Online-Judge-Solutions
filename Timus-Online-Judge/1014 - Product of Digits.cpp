#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long int n, i, idx;
    char str[11];
    bool flag;

    cin >> n;

    if(n == 0) cout << "10\n";
    else if(n == 1) cout << "1\n";
    else {
        idx = 0;

        while(n > 1) {
            flag = 0;

            for(i = 9; i > 1; i--) {
                if(n % i == 0) {
                    str[idx++] = i + '0';
                    n /= i;
                    flag = 1;
                    break;
                }
            }

            if(!flag) break;
        }

        if(flag) {
            str[idx] = '\0';

            sort(str, str+idx);

            cout << str << '\n';
        }
        else
            cout << "-1\n";
    }

    return 0;
}
