#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int tc;
    cin >> tc;

    while(tc--) {
        int ax, ay, bx, by, cx, cy, dx, dy;

        cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

        int ans_LL_x, ans_LL_y, ans_UR_x, ans_UR_y;

        ans_LL_x = max(ax, cx);
        ans_LL_y = max(ay, cy);
        ans_UR_x = min(bx, dx);
        ans_UR_y = min(by, dy);

        if(ans_LL_x >= ans_UR_x || ans_LL_y >= ans_UR_y)
            cout << "No Overlap\n";
        else
            cout << ans_LL_x << ' ' << ans_LL_y << ' ' << ans_UR_x << ' ' << ans_UR_y << '\n';

        if(tc) cout << '\n';
    }
}


// ============================= Alternative solution =============================
/*

#include <iostream>
using namespace std;

typedef     pair<int,int>   ii;

ii rec1_LL, rec1_UR, rec2_LL, rec2_UR;

bool is_in(int x, int y)
{
    bool is_in_first_rec = false, is_in_second_rec = false;

    if(rec1_LL.first <= x && x <= rec1_UR.first && rec1_LL.second <= y && y <= rec1_UR.second)
        is_in_first_rec = true;

    if(rec2_LL.first <= x && x <= rec2_UR.first && rec2_LL.second <= y && y <= rec2_UR.second)
        is_in_second_rec = true;

    return (is_in_first_rec && is_in_second_rec);
}

bool get_the_point(ii more, ii less, ii &ret)
{
    if(is_in(more.first, more.second)) { ret = more; return true; }
    if(is_in(more.first, less.second)) { ret = ii(more.first, less.second); return true; }
    if(is_in(less.first, more.second)) { ret = ii(less.first, more.second); return true; }
    if(is_in(less.first, less.second)) { ret = ii(less.first, less.second); return true; }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);

    int tc;
    cin >> tc;

    while(tc--) {
        cin >> rec1_LL.first >> rec1_LL.second >> rec1_UR.first >> rec1_UR.second;
        cin >> rec2_LL.first >> rec2_LL.second >> rec2_UR.first >> rec2_UR.second;

        ii more, less, ans1, ans2;

        more = min(rec1_LL, rec2_LL);
        less = max(rec1_LL, rec2_LL);

        if(get_the_point(more, less, ans1)) {
            more = max(rec1_UR, rec2_UR);
            less = min(rec1_UR, rec2_UR);

            if(get_the_point(more, less, ans2) && ans1.first != ans2.first && ans1.second != ans2.second)
                    cout << ans1.first << ' ' << ans1.second << ' ' << ans2.first << ' ' << ans2.second << '\n';
            else
                cout << "No Overlap\n";
        }
        else cout << "No Overlap\n";

        if(tc) cout << '\n';
    }

    return 0;
}

*/
