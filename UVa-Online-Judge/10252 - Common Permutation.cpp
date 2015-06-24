#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define SZ 1001

int main()
{
    char a[SZ], b[SZ], x[SZ];

    while(cin.getline(a, SZ) && cin.getline(b, SZ)) {
        int len_a, len_b;

        len_a = strlen(a);
        len_b = strlen(b);

        int idx = 0;

        for(int i = 0; i < len_a; ++i) {
            for(int j = 0; j < len_b; ++j) {
                if(a[i] == b[j]) {
                    x[idx++] = a[i];
                    b[j] = ' ';
                    break;
                }

            }
        }
        x[idx] = '\0';

        sort(x, x+idx);

        cout << x << '\n';
    }

    return 0;
}
