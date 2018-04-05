// ==================================================
// Problem  :   2102. Michael and Cryptography
// Run time :   0.046 sec.
// Language :   C++
// ==================================================


#include <cstdio>
#include <cmath>
using namespace std;


typedef     long long       LL;


int main()
{
    LL n;
    scanf("%lld", &n);

    int rt = sqrt(n), psum = 0;
    LL  curr = n;
    bool ans = true;

    for(int i = 2; i <= rt and i <= curr; ++i) {
        while(curr % i == 0) {
            ++psum;
            curr /= i;
        }

        if(psum > 20) {
            ans = false;
            break;
        }
        else if(psum == 20 ) {
            if(curr != 1) ans = false;
            break;
        }
        else if(psum == 19) {
            if((i+1)*(i+1) > curr) {
                if(i+1 <= curr) break;
                else {
                    ans = false;
                    break;
                }
            }
        }

        if(pow(i + 1, 20 - psum) > curr) {
            ans = false;
            break;
        }
    }

    if(ans and curr != 1) {
        ++psum;
    }

    if(psum != 20) {
        ans = false;
    }

    puts(ans ? "Yes" : "No");

    return 0;
}
