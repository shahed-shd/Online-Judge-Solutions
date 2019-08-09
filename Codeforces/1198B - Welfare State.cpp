// ==================================================
// Problem  :   1198B - Welfare State
// Run time :   0.249 sec
// Language :   C++17
// ==================================================


#include <cstdio>
#include <vector>
using namespace std;

vector<int> vec_balance, vec_last_receipt_idx, vec_payoff;

int main()
{
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    int a;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a);
        vec_balance.push_back(a);
    }

    // vec_last_receipt_idx[i] will contain the index of the event in which the i-th citizen sent his last receipt.
    vec_last_receipt_idx.assign(n, -1);

    int q, event_type, p, x;
    scanf("%d", &q);

    // vec_payoff[i] will contain the payoff amount of the i-th event.
    vec_payoff.assign(q, -1);

    for(int i = 0; i < q; ++i) {
        scanf("%d", &event_type);

        if(event_type == 1) {
            scanf("%d %d", &p, &x);
            --p;
            vec_balance[p] = x;
            vec_last_receipt_idx[p] = i;
        }
        else {
            scanf("%d", &x);
            vec_payoff[i] = x;
        }
    }

    // Now, vec_payoff[i] will contain the max payoff from i-th event to the last event.
    for(int i = q-2; i >= 0; --i) {
        vec_payoff[i] = max(vec_payoff[i], vec_payoff[i+1]);
    }

    for(int i = 0; i < n; ++i) {
        int j = max(0, vec_last_receipt_idx[i]);
        printf("%d ", max(vec_balance[i], vec_payoff[j]));
    }

    return 0;
}
