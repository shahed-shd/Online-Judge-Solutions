#include <cstdio>
#include <list>
using namespace std;

typedef     list<int>::iterator     list_it;

list<int> circle;

list_it clock_wise(list_it from, int dist);
list_it counter_clock_wise(list_it from, int dist);

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n, k, m;

    while(scanf("%d %d %d", &n, &k, &m), n) {
        circle.clear();

        for(int i = 1; i <= n; ++i)
            circle.push_back(i);

        list_it it1, it2;

        it1 = circle.begin(), it2 = circle.end(), --it2;

        bool f = true;

        while(!circle.empty()) {
            if(!f) putchar(',');
            f = false;

            it1 = counter_clock_wise(it1, k % circle.size() - 1);
            it2 = clock_wise(it2, m % circle.size() - 1);

            if(it1 == it2) {
                printf("%3d", *it1);

                it2 = clock_wise(it2, 1);

                it1 = circle.erase(it1);
                if(it1 == circle.end()) it1 = circle.begin();
            }
            else {
                printf("%3d%3d", *it1, *it2);

                list_it tmp = it2;
                it2 = clock_wise(it2, 1);
                circle.erase(tmp);

                if(it2 == it1) it2 = clock_wise(it2, 1);
                it1 = circle.erase(it1);
                if(it1 == circle.end()) it1 = circle.begin();
            }
        }

        putchar('\n');
    }

    return 0;
}

list_it counter_clock_wise(list_it from, int dist)
{
    if(dist < 0) return clock_wise(from, -dist);

    while(dist--)
        if(++from == circle.end())
            from = circle.begin();

    return from;
}

list_it clock_wise(list_it from, int dist)
{
    if(dist < 0) return counter_clock_wise(from, -dist);

    while(dist--)
        if(from-- == circle.begin())
            from = circle.end(), --from;

    return from;
}
