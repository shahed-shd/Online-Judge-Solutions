#include <cstdio>
#include <algorithm>
#include <sstream>
#include <vector>
#include <climits>
using namespace std;

const int INF = 50000*100;

struct teacher {
    int salary;
    int subjectMask = 0;
};

int s, n, memo[100][1<<8][1<<8];
vector<teacher> newTeachers;

inline int biton(int n, int pos) { return n | (1<<pos); }
inline bool bitcheck(int n, int pos) { return (n>>pos) & 1; }

int fn(int idx, int mask1, int mask2)
{
    if(mask1 == (1<<s)-1 && mask2 == (1<<s)-1) return 0;    // Every subject has at least 2 teachers.
    if(idx == n) return INF;                                // Now, no teacher.

    int& ret = memo[idx][mask1][mask2];
    if(ret != -1) return ret;                               // If already memorized.

    int  mn = INT_MAX;

    mn = min(mn, fn(idx+1, mask1, mask2));                  // Without employing this new teacher.

    mask2 |= mask1 & newTeachers[idx].subjectMask;
    mask1 |= newTeachers[idx].subjectMask;

    mn = min(mn, newTeachers[idx].salary+fn(idx+1, mask1, mask2));  // Employing this new teacher.

    return ret = mn;
}

int main()
{
    //freopen("in", "r", stdin);

    int m;

    while(scanf("%d %d %d", &s, &m, &n), s) {
        newTeachers.clear();

        getchar();

        int alreadyCost = 0, subjectMask1 = 0, subjectMask2 = 0;

        while(m--) {
            char str[50];
            fgets(str, sizeof(str), stdin);
            stringstream ss(str);
            int tmp;

            ss >> tmp;
            alreadyCost += tmp;

            while(ss >> tmp) {
                --tmp;

                if(!bitcheck(subjectMask1, tmp))
                    subjectMask1 = biton(subjectMask1, tmp);
                else
                    subjectMask2 = biton(subjectMask2, tmp);
            }
        }

        newTeachers.resize(n);

        for(int i = 0; i < n; ++i) {
            char str[50];
            fgets(str, sizeof(str), stdin);
            stringstream ss(str);
            int tmp;

            ss >> tmp;
            newTeachers[i].salary = tmp;

            while(ss >> tmp)
                newTeachers[i].subjectMask = biton(newTeachers[i].subjectMask, tmp-1);
        }

        fill(&memo[0][0][0], &memo[100][0][0], -1);

        printf("%d\n", alreadyCost + fn(0, subjectMask1, subjectMask2));
    }

    return 0;
}
