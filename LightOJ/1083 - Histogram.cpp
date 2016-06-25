#include <cstdio>
#include <stack>
using namespace std;

typedef     pair<int,int>       ii;

template<class T>
inline T fastIn()
{
    register char ch = 0;
    register T a = 0;
    bool neg = false;

    while(ch < 33) ch = getchar();

    if(ch == '-') neg = true;
    else a = ch - '0';

    while(ch = getchar(), ch > 33)
        a = a * 10 + (ch - '0');

    return ((neg)? -a : a);
}

int main()
{
    //freopen("in", "r", stdin);

    int t = fastIn<int>();

    for(int tc = 1; tc <= t; ++tc) {
        int n = fastIn<int>();

        int arr[n+3], left[n+3], right[n+3];

        for(int i = 1; i <= n; ++i) {
            arr[i] = fastIn<int>();
            left[i] = right[i] = i;
        }

        stack<ii> st;

        for(int i = 1; i <= n; ++i) {
            if(st.empty() || arr[i] >= st.top().first) {
                st.push(ii(arr[i], i));
            }
            else {
                while(!st.empty() && arr[i] < st.top().first) {
                    left[i] = left[st.top().second];
                    right[st.top().second] = i-1;
                    st.pop();
                }

                st.push(ii(arr[i], i));
            }
        }

        while(!st.empty()) {
            right[st.top().second] = n;
            st.pop();
        }

        int mx = 0;

        for(int i = 1; i <= n; ++i)
            mx = max(mx, arr[i] * (right[i]-left[i]+1));

        printf("Case %d: %d\n", tc, mx);
    }

    return 0;
}
