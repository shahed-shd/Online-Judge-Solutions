// ==================================================
// Problem  :   1198A - MP3
// Run time :   0.140 sec
// Language :   C++17
// ==================================================


#include <cstdio>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

vector<int> vec_a, freq, cum_freq;

int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int n, available_bytes;
    scanf("%d %d", &n, &available_bytes);

    int a;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        vec_a.push_back(a);
    }

    // Frequencty of the numbers
    sort(vec_a.begin(), vec_a.end());

    a = vec_a.front();
    freq.push_back(1);

    for(int i = 1; i < n; ++i) {
        if(vec_a[i] == a) {
            freq.back() += 1;
        }
        else {
            a = vec_a[i];
            freq.push_back(1);
        }
    }

    int tot_distinct_num = freq.size();

    // Cumulative sum of frequencty
    cum_freq.resize(tot_distinct_num);
    partial_sum(freq.begin(), freq.end(), cum_freq.begin());

    // Max unchanged count
    int each_num_occupied_bits = available_bytes * 8 / n;
    int tot_distinct_num_capable = 1 << min(each_num_occupied_bits, 20);    // log2(MAXN) < 20, where MAXN = 4e5
    int unchanged_count = 0;

    for(int i = min(tot_distinct_num_capable, tot_distinct_num)-1; i < tot_distinct_num; ++i) {
        int s = i-tot_distinct_num_capable;
        int curr_unchanged_cout = cum_freq[i] - (s < 0? 0 : cum_freq[s]);
        unchanged_count = max(unchanged_count, curr_unchanged_cout);
    }

    // Min changed count
    printf("%d\n", n - unchanged_count);

    return 0;
}
