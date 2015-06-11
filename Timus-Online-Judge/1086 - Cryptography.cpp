#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int n)
{
    //if(n < 2) return 0;
    //else if(n == 2) return 1;
    //else if(n%2 == 0) return 0;    // this lines aren't necessary for this program.

    int root = sqrt(n);

    for(int i = 3; i <= root; i += 2) {
        if(n % i == 0) return 0;
    }

    return 1;
}

int main()
{
    int k, i, n, *num, prime_num[15001] = {0, 2};    // 2 is in position 1.

    for(n = 3, i = 2; i <= 15000; n += 2)
        if(is_prime(n)) prime_num[i++] = n;

    cin >> k;

    num = new int [k];

    for(i = 0; i < k; i++) cin >> num[i];

    for(i = 0; i < k; i++)
        cout << prime_num[num[i]] << '\n';

    delete [] num;

    return 0;
}
