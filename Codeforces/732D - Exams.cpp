// ==================================================
// Problem  :   732D - Exams
// Run time :   0.046 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

typedef     long long       LL;

class BIT {
    vector<LL> tree;
    int sz;

public:
    BIT(int n) {
        sz = n+3;
        tree.assign(sz, 0);
    }

    void update(int idx, int val) {
        while(idx < sz) {
            tree[idx] += val;
            idx += idx & (-idx);
        }
    }

    int query(int idx) {
        int sum = 0;

        while(idx > 0) {
            sum += tree[idx];
            idx -= idx & (-idx);
        }

        return sum;
    }
};

int main()
{
    //freopen("in", "r", stdin);

    int n, m;
    scanf("%d %d", &n, &m);

    int exams[n+3], daysNeeded[m+3];

    for(int i = 1; i <= n; ++i)
        scanf("%d", exams+i);

    LL totalDaysNeeded = 0;

    for(int i = 1; i <= m; ++i) {
        scanf("%d", daysNeeded+i);
        ++daysNeeded[i];        // One day more to pass the exam.
        totalDaysNeeded += daysNeeded[i];
    }

    if(totalDaysNeeded > n) {
        puts("-1");
        return 0;
    }

    BIT bit(n);
    vector<int> lastIdx(m+3, -1);
    stack<int> problemIdx;
    LL totalDays = 0;
    int passCnt = 0, ans = -1;

    for(int i = 1; i <= n; ++i) {
        if(exams[i]) {
            int exm = exams[i];

            if(lastIdx[exm] == -1) {
                ++passCnt;
                lastIdx[exm] = i;

                totalDays += daysNeeded[exm];
                bit.update(i, daysNeeded[exm]);
            }
            else {
                bit.update(lastIdx[exm], -daysNeeded[exm]);
                bit.update(i, daysNeeded[exm]);
                lastIdx[exm] = i;
            }

            if(i < totalDays) {
                problemIdx.push(i);
            }

            while(!problemIdx.empty()) {
                int p = problemIdx.top();

                if(p >= bit.query(p))
                    problemIdx.pop();
                else
                    break;
            }

            if(passCnt == m && problemIdx.empty()) {
                ans = i;
                break;
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
