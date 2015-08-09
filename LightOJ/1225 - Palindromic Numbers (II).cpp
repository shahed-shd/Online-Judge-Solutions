// Strange experience, I faced TLE with C++ i/o system,
// C i/o is faster than that of C++.

//#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
    long int t, tc, i, len;
    char str[11];

    //cin >> t;
    scanf("%ld", &t);
    tc = 0;

    while(t--) {
        //cin >> str;
        scanf("%s", str);

        len = strlen(str);

        for(i = 0; i < len/2 && str[i] == str[len-i-1]; i++);

        if(i < len/2) //cout << "Case " << ++tc << ": No\n";
            printf("Case %ld: No\n", ++tc);
        else //cout << "Case " << ++tc << ": Yes\n";
            printf("Case %ld: Yes\n", ++tc);
    }

    return 0;
}
