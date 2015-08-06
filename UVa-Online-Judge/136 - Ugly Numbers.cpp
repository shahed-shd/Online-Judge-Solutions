#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue<long long int, vector<long long int>, greater<long long int> > pq;
    long long int current_ugly;
    int n;

    current_ugly = 1;
    n = 1;

    pq.push(2);
    pq.push(3);
    pq.push(5);

    while(n < 1500) {
        int temp_current_ugly = pq.top();   // get smallest.
        pq.pop();

        int temp = pq.top();        // remove the values which are equal to the smallest.
        while(temp == temp_current_ugly) {
            pq.pop();
            temp = pq.top();
        }

        current_ugly = temp_current_ugly;
        ++n;

        pq.push(current_ugly * 2);
        pq.push(current_ugly * 3);
        pq.push(current_ugly * 5);
    }

    cout << "The 1500'th ugly number is " << current_ugly << ".\n";

    return 0;
}


// Alternative solution.
/*
#include <iostream>
using namespace std;

int main()
{
    int dp[1500] = {1};

    int p2, p3, p5, p_end;

    p2 = p3 = p5 = p_end = 0;

    while(p_end < 1499) {
        while(dp[p2] * 2 <= dp[p_end]) ++p2;

        while(dp[p3] * 3 <= dp[p_end]) ++p3;

        while(dp[p5] * 5 <= dp[p_end]) ++p5;


        if(dp[p2] * 2 <= dp[p3] * 3 && dp[p2] * 2 <= dp[p5] * 5) {
            dp[++p_end] = dp[p2++] * 2;
        }
        else if(dp[p3] * 3 <= dp[p2] * 2 && dp[p3] * 3 <= dp[p5] * 5) {
            dp[++p_end] = dp[p3++] * 3;
        }
        else {
            dp[++p_end] = dp[p5++] * 5;
        }
    }

    cout << "The 1500'th ugly number is " << dp[p_end] << ".\n";

    return 0;
}
*/
