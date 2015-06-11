// C++ i/o system got TLE. so, C i/o is faster than that of C++.

//#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n, *k, i, value, most_common_value, cnt, max_cnt;

    //cin >> n;
    scanf("%d", &n);

    k = new int [n];

    for(i = 0; i < n; i++) scanf("%d", k+i); //cin >> k[i];

    sort(k, k+n);

    i = 0;
    max_cnt = 0;

    while(i < n) {
        cnt = 0;
        value = k[i];

        while(i < n && value == k[i]) {
            cnt++;
            i++;
        }

        if(cnt > max_cnt) {
            most_common_value = value;
            max_cnt = cnt;
        }
    }

    //cout << most_common_value << '\n';
    printf("%d\n", most_common_value);

    delete [] k;

    return 0;
}
