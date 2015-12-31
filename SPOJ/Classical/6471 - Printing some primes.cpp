#include <cstdio>
#include <bitset>
using namespace std;

const int maxN = 100000000;

bitset<maxN+5> status;

int main()
{
    for(int i = 4; i < maxN; i += 2) status[i] = true;

    for(int i = 3; i <= 10000; i += 2) {
        if(!status[i]) {
            for(int j = i*i; j < maxN; j += i<<1)
                status[j] = true;
        }
    }

    int cnt = 0;

    for(int i = 2; i < maxN; ++i) {
        if(!status[i]) {
            ++cnt;

            if(cnt % 100 == 1)
                printf("%d\n", i);
        }
    }

    return 0;
}
