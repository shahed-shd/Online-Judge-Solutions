#include <cstdio>
#include <climits>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int s, niceness;
        scanf("%d", &s);

        // Kadane's algorithm.

        int currSum, currStart, currEnd, maxSum, maxStart, maxEnd;

        maxSum = - INT_MAX;
        currSum = 0;
        currStart = 1;

        for(currEnd = 1; currEnd < s; ++currEnd) {
            scanf("%d", &niceness);

            currSum += niceness;

            if(currSum > maxSum || (currSum == maxSum && currEnd-currStart > maxEnd-maxStart)) {
                maxSum = currSum;
                maxStart = currStart;
                maxEnd = currEnd;
            }

            if(currSum < 0) {
                currSum = 0;
                currStart = currEnd + 1;
            }
        }

        if(maxSum > 0) printf("The nicest part of route %d is between stops %d and %d\n", tc, maxStart, maxEnd+1);
        else printf("Route %d has no nice parts\n", tc);
    }

    return 0;
}
