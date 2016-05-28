#include <cstdio>
#include <map>
#include <utility>
using namespace std;

typedef     long long       LL;
typedef     pair<LL,bool>   LLB;

LL n;
map<LLB, bool> mp;

bool winner(LL p, bool who)
{
    if(p >= n) return !who;

    if(mp.find(LLB(p, who)) != mp.end()) return mp[LLB(p, who)];

    bool ret = !who;

    for(int i = 2; i <= 9; ++i) {
        ret = winner(p*i, !who);
        if(ret == who) break;
    }

    mp[LLB(p, who)] = ret;
    return ret;
}

int main()
{
    //freopen("in.txt", "r", stdin);

    while(scanf("%lld", &n) != EOF) {
        mp.clear();

        (winner(1, true))? puts("Stan wins.") : puts("Ollie wins.");
    }

    return 0;
}
