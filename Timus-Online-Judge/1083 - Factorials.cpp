#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n, k, i, mod, ans;
    char marks[21];

    cin >> n >> marks;

    k = strlen(marks);

    mod = n % k;
    ans = 1;

    if(mod)
        for(i = n; i >= mod; i -= k) ans *= i;
    else
        for(i = n; i >= k; i -= k) ans *= i;

    cout << ans << '\n';


    return 0;
}
