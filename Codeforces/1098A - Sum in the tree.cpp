// ==================================================
// Problem  :   1098A - Sum in the tree
// Run time :   0.233 sec
// Language :   C++17
// ==================================================


#include <iostream>
#include <bitset>
using namespace std;


typedef     long long       LL;


const int MAXN = 1e5 + 3;


int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int n;
    cin >> n;

    int arr_p[MAXN];

    for(int i = 2; i <= n; ++i) {
        cin >> arr_p[i];
    }

    bool does_exist = true;
    LL sum_upto[MAXN];
    bitset<MAXN> is_min_calculated;

    cin >> sum_upto[1];

    for(int i = 2; i <= n; ++i) {
        cin >> sum_upto[i];
        int p = arr_p[i];           // Parent of vertex i

        if(sum_upto[i] == -1) {     // Even depth vertex
        	sum_upto[i] = sum_upto[p];
        }
        else {                      // Odd depth vertex
        	int pp = arr_p[p];      // Parent of parent of vertex i
        	LL sum_temp = sum_upto[i] - sum_upto[pp];   // Sum of vertex i and p

        	if(sum_temp < 0) {
        		does_exist = false;
        		break;
        	}

        	if(is_min_calculated[p]) {
        		sum_upto[p] = min(sum_upto[p], sum_upto[pp] + sum_temp);
        	}
        	else {
        		sum_upto[p] = sum_upto[pp] + sum_temp;
        		is_min_calculated[p] = true;
        	}
        }
    }

    LL ans = sum_upto[1];

    if(does_exist) {
        for(int i = 2; i <= n; ++i) {
            int p = arr_p[i];
            ans += sum_upto[i] - sum_upto[p];   // Value of vertex i is added to ans
        }
    }

    cout << (does_exist? ans : -1);

    return 0;
}
