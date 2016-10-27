// ==================================================
// Problem  :   The Maximum Subarray
// Score    :   50 /50
// Language :   C++
// ==================================================

#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

template<class T>
inline T fastIn()
{
    register char c = 0;
    register T a = 0;
    bool neg = false;

    while(c < 33) c = getchar();

    if(c == '-') neg = true;
    else a = c - '0';

    while(c = getchar(), c > 33)
        a = a * 10 + (c - '0');

    return (neg? -a : a);
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int t = fastIn<int>();

    while(t--) {
        int n = fastIn<int>();

        int contiguousSum = INT_MIN, currContiguousSum = 0, nonContiguousSum = 0, ai;
        int maxNum = INT_MIN;
        bool isAnyNonNegative = false;

        for(int i = 0; i < n; ++i) {
            ai = fastIn<int>();

            currContiguousSum += ai;

            if(currContiguousSum > contiguousSum)
                contiguousSum = currContiguousSum;

            if(currContiguousSum < 0) {
                currContiguousSum = 0;
            }

            if(ai >= 0) {
                isAnyNonNegative = true;
                nonContiguousSum += ai;
            }
            maxNum = max(maxNum, ai);
        }

        if(!isAnyNonNegative) nonContiguousSum = maxNum;

        printf("%d %d\n", contiguousSum, nonContiguousSum);
    }

    return 0;
}
