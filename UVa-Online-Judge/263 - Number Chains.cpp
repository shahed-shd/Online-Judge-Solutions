#include <iostream>
#include <algorithm>
#include <map>
#include <cstdio>
#include <cstring>
using namespace std;

void get_asc_desc(int n, int &asc, int &desc)
{
    char str[11];

    sprintf(str, "%d", n);

    sort(str, str+strlen(str));

    asc = atoi(str);

    sort(str, str+strlen(str), greater<char>());

    desc = atoi(str);
}

int main()
{
    ios_base::sync_with_stdio(false);

    map<int, bool> mymap;
    int nmbr;

    while(cin >> nmbr, nmbr != 0) {
        cout << "Original number was " << nmbr << '\n';

        int asc, desc, cnt = 0;
        bool flag = false;
        mymap.clear();

        do {
            if(flag) mymap[nmbr] = true;
            flag = true;

            get_asc_desc(nmbr, asc, desc);

            nmbr = desc - asc;
            ++cnt;

            cout << desc << " - " << asc << " = " << nmbr << '\n';
        }while(mymap[nmbr] != true);

        cout << "Chain length " << cnt << "\n\n";
    }

    return 0;
}
