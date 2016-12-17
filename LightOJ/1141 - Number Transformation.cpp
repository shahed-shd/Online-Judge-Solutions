// ==================================================
// Problem  :   1141 - Number Transformation
// Run time :   0.032 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <bitset>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

#define     ff                  first
#define     ss                  second

typedef     pair<int,int>       ii;

const int MAXT = 1000 + 3;

bitset<MAXT> status;
vector<int> primes;

void sieve()
{
    status[0] = status[1] = true;
    status[2] = false;

    for(int i = 4; i < MAXT; i+=2) status[i] = true;

    int rt = sqrt(MAXT);

    for(int i = 3; i <= rt; i+=2)
        if(!status[i])
            for(int j = i*i; j < MAXT; j+=(i<<1))
                status[j] = true;

    primes.push_back(2);

    for(int i = 3; i < MAXT; i+=2)
        if(!status[i])
            primes.push_back(i);
}

void factorize(int n, vector<int> &V)
{
    int sz = primes.size();

    for(int i = 0; i < sz && primes[i]*primes[i] <= n; ++i) {
        if(n % primes[i] == 0) {
            V.push_back(primes[i]);
            while(n % primes[i] == 0) n /= primes[i];
        }
    }

    if(n != 1) V.push_back(n);
}

int bfs(int s, int t)
{
    queue<ii> q;
    bool vis[MAXT] = {false};

    q.push(ii(0, s));
    vis[s] = true;

    while(!q.empty()) {
        int d = q.front().ff, n = q.front().ss;
        q.pop();

        if(n == t) return d;

        if(!status[n]) continue;

        vector<int> factors;
        factorize(n, factors);
        int sz = factors.size();

        for(int i = 0; i < sz; ++i) {
            if(n + factors[i] <= t && !vis[n+factors[i]]) {
                vis[n+factors[i]] = true;
                q.push(ii(d+1, n+factors[i]));
            }
        }
    }

    return -1;
}

int main()
{
    sieve();

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int s, t;
        scanf("%d %d", &s, &t);

        printf("Case %d: %d\n", tc, bfs(s, t));
    }

    return 0;
}
