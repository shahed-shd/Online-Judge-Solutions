// An amazing experience !
// If I use cin.getline() in 58th line, the verdict shows TLE of 3.000 sec.
// If I use scanf(), the program is ACCEPTED with run-time 0.050 sec !!!

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

void calculate_cycle(int *arr, int n, int *cycle)
{
    int element, cnt;
    bool *is_cycled, *temp;

    temp = new bool [n];
    is_cycled = new bool [n];
    memset(is_cycled, 0, n);

    for(int i = 0; i < n; ++i) {
        if(is_cycled[i]) continue;

        memset(temp, 0, n);
        element = i+1;
        cnt = 0;

        do {
            is_cycled[element-1] = temp[element-1] = true;
            element = arr[element-1];
            ++cnt;
        }while(element != i+1);

        for(int j = 0; j < n; ++j)
            if(temp[j]) cycle[j] = cnt;
    }

    delete [] is_cycled;
    delete [] temp;
}

int main()
{
    int n, k, i, *arr, *cycle;
    char *str, *ans;

    while(cin >> n, n != 0) {
        arr = new int [n];
        cycle = new int [n];

        str = new char [n+1];
        ans = new char [n+1];

        for(i = 0; i < n; ++i) cin >> arr[i];

        calculate_cycle(arr, n, cycle);

        while(cin >> k, k != 0) {
            cin.ignore(1, ' ');
            scanf("%[^\n]", str); //cin.getline(str, n);

            int len = strlen(str);

            if(len < n) for(i = len; i < n; ++i) str[i] = ' ';

            str[n] = ans[n] = '\0';

            for(i = 0; i < n; ++i) {
                int cy = k % cycle[i];
                int temp = i+1;

                while(cy--) temp = arr[temp-1];

                ans[temp-1] = str[i];
            }

            cout << ans << '\n';
        }

        cout << '\n';

        delete [] arr;
        delete [] cycle;
        delete [] str;
        delete [] ans;
    }

    return 0;
}


// Alternative & simplified ACCEPTED solution.
/*
#include <cstdio>
#include <cstring>
using namespace std;

#define SZ 205

void calculate_cycle(int *arr, int n, int *cycle)
{
    int element, cnt;

    for(int i = 0; i < n; ++i) {
        element = arr[i];
        cnt = 1;

        while(element != i+1) {
            element = arr[element-1];
            ++cnt;
        }

        cycle[i] = cnt;
    }
}

int main()
{
    int n, k, i, arr[SZ], cycle[SZ];
    char str[SZ], ans[SZ];

    while(scanf("%d", &n), n) {

        for(i = 0; i < n; ++i) scanf("%d", &arr[i]);

        calculate_cycle(arr, n, cycle);

        while(scanf("%d", &k), k) {
            scanf("%*c");
            scanf("%[^\n]", str);

            int len = strlen(str);

            if(len < n) for(i = len; i < n; ++i) str[i] = ' ';

            str[n] = ans[n] = '\0';

            for(i = 0; i < n; ++i) {
                int cy = k % cycle[i];

                int temp = i+1;

                while(cy--) temp = arr[temp-1];

                ans[temp-1] = str[i];
            }

            printf("%s\n", ans);
        }

        printf("\n");
    }

    return 0;
}
*/
