// ==================================================
// Problem  :   1077C - Good Array
// Run time :   0.077 sec
// Language :   C++17
// ==================================================


#include <cstdio>
#include <vector>
using namespace std;


typedef     long long       LL;

const int MAXN = 2e5 + 3;
const int MAXA = 1e6 + 3;

int arr[MAXN];
int frequency[MAXA] = {0};
vector<int> ansV;

int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    LL sum = 0;
    int a;

    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        arr[i] = a;
        ++frequency[a];
        sum += a;
    }

    for(int i = 0; i < n; ++i) {
        LL rem = sum - arr[i];
        if(rem >= 0 and !(rem & 1)) {
            LL k = rem / 2;
            if(k >= MAXA) continue;
            if((frequency[k] > 1) or (frequency[k] == 1 and arr[i] != k)) {
                ansV.push_back(i);
            }
        }
    }

    printf("%d\n", int(ansV.size()));

    for(auto &x : ansV) {
        printf("%d ", x+1);
    }

    return 0;
}
