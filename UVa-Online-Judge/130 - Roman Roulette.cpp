#include <cstdio>
#include <list>
using namespace std;

typedef     list<int>::iterator     list_it;

list_it iteratorAdvance(list_it from, int dist, list<int> &circle)
{
    while(dist--) {
        ++from;

        if(from == circle.end())
            from = circle.begin();
    }

    return from;
}

int get_survivor_if_start_from(int start, int n, int k, list<int> circle)
{
    list_it it1, it2;

    it1 = circle.begin();
    it1 = iteratorAdvance(it1,  start-1, circle);

    bool starting = true;

    while(circle.size() > 1) {
        it1 = iteratorAdvance(it1, ((starting)?k-1:k), circle);
        starting = false;

        it1 = circle.erase(it1);    // promptly killed.
        if(it1 == circle.end()) it1 = circle.begin();

        it2 = iteratorAdvance(it1, k-1, circle);

        it1 = circle.insert(it1, *it2);

        circle.erase(it2);
    }

    return circle.front();
}

int main()
{
    int n, k;

    while(scanf("%d %d", &n, &k), n || k) {
        list<int> circle;

        for(int i = 1; i <= n; ++i)
            circle.push_back(i);

        for(int i = 1; i <= n; ++i) {
            if(get_survivor_if_start_from(i, n, k, circle) == 1) {
                printf("%d\n", i);
                break;
            }
        }
    }

    return 0;
}
