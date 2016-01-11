#include <cstdio>
#include <algorithm>
#include <bitset>
#include <unordered_map>
using namespace std;

struct contestant {
    short id;
    short solved = 0;
    short totalPenalty = 0;

    bitset<9> isSolved;
    short timePenaltyPrior[9] = {0};

    void put_id(short i) { id = i; }

    void correct(short p, short time) {  // p for problem number.
        if(isSolved[p]) return;

        isSolved[p] = true;
        ++solved;
        totalPenalty += time + timePenaltyPrior[p];
    }

    void incorrect(short p) {
        if(isSolved[p]) return;
        timePenaltyPrior[p] += 20;
    }
};

struct score {
    short id, solved, penalty;

    score(int i, int s, int p) {    // constructor.
        id = i, solved = s, penalty = p;
    }

    bool operator<(const score& b) const {  // operator overloading.
        if(solved != b.solved)
            return solved > b.solved;

        if(penalty != b.penalty)
            return penalty < b.penalty;

        return id < b.id;
    }
};

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int tc;
    scanf("%d\n\n", &tc);

    while(tc--) {
        char str[15];
        unordered_map<short, contestant> mp;

        while(fgets(str, sizeof(str), stdin) != NULL && str[0] != '\n') {
            short id, problemNumber, time;
            char ch;

            sscanf(str, "%hd %hd %hd %c", &id, &problemNumber, &time, &ch);

            mp[id].put_id(id);

            if(ch == 'C')
                mp[id].correct(problemNumber-1, time);
            else if(ch == 'I')
                mp[id].incorrect(problemNumber-1);
        }

        vector<score> ans;

        for(auto& pr : mp) {
            auto& x = pr.second;
            ans.push_back(score(x.id, x.solved, x.totalPenalty));
        }

        sort(ans.begin(), ans.end());

        for(auto& x : ans)
            printf("%d %d %d\n", x.id, x.solved, x.penalty);

        if(tc) putchar('\n');
    }

    return 0;
}
