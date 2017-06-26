// ==================================================
// Problem  :   10141 - Request for Proposal
// Run time :   0.000 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

const int MAXN = 1000 + 3;

struct node {
    int r, serial_no;
    double price;
};

node arr[MAXN];
string names[MAXN];

bool node_comp(const node &a, const node &b)
{
    if(a.r == b.r) {
        if(a.price == b.price) {
            return a.serial_no < b.serial_no;
        }
        else return a.price < b.price;
    }
    else return a.r > b.r;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int n, p, tc = 0;

    while(scanf("%d %d", &n, &p), n and p) {
        char s[100];

        getchar();
        while(n--) fgets(s, 100, stdin);

        for(int i = 0; i < p; ++i) {
            fgets(s, 100, stdin);
            int len = strlen(s);
            if(s[len-1] == '\n') s[len-1] = '\0';
            names[i] = string(s);

            scanf("%lf %d\n", &arr[i].price, &arr[i].r);
            arr[i].serial_no = i;

            int req = arr[i].r;
            while(req--) fgets(s, 100, stdin);
        }

        sort(arr, arr+p, node_comp);

        if(tc) putchar('\n');
        printf("RFP #%d\n%s\n", ++tc, names[arr[0].serial_no].c_str());
    }

    return 0;
}
