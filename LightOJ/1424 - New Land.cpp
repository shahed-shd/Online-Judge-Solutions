// ==================================================
// Problem  :   1424 - New Land
// Run time :   0.288 sec.
// Language :   C++
// ==================================================

#include <cstdio>
#include <stack>
using namespace std;

const int MAXN = 2000 + 3;

int max_rec_area_in_histogram(int hist[], int n)
{
    stack<int> st;
    int maxArea = 0;

    for(int i = 1; i <= n; ++i) {
        if(st.empty() || hist[st.top()] <= hist[i])
            st.push(i);
        else {
            while(!st.empty() && hist[st.top()] > hist[i]) {
                int t = st.top();
                st.pop();

                maxArea = max(maxArea, hist[t] * ((st.empty())? i-1 : i - st.top() - 1));
            }

            st.push(i);
        }
    }

    while(!st.empty()) {
        int t = st.top();
        st.pop();

        maxArea = max(maxArea, hist[t] * ((st.empty())? t : t - st.top()));
    }

    return maxArea;
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d", &t);

    for(int tc = 1; tc <= t; ++tc) {
        int m, n;
        scanf("%d %d\n", &m, &n);

        int arr[MAXN] = {0}, maxArea = 0;
        char str[MAXN];

        while(m--) {
            fgets(&str[1], MAXN-1, stdin);

            for(int i = 1; i <= n; ++i)
                arr[i] = (str[i] == '1')? 0 : arr[i]+1;

            maxArea = max(maxArea, max_rec_area_in_histogram(arr, n));
        }

        printf("Case %d: %d\n", tc, maxArea);
    }

    return 0;
}
