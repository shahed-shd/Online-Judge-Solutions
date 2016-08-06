#include <cstdio>
using namespace std;

class circular_list {   // linked list concept.
    struct node {
        int serial_num;
        node *prev, *next;
    };

    node *start;
    int n;

public:
    circular_list(int n) {
        this->n = n;
        int s = 0;
        start = new node;

        start->serial_num = ++s;
        start->next = new node;

        node *curr = start->next;
        curr->prev = start;

        while(s < n-1) {
            curr->serial_num = ++s;
            curr->next = new node;

            node *tmp = curr;
            curr = curr->next;
            curr->prev = tmp;
        }

        curr->next = start;
        start->prev = curr;
    }

    node* remove(node *curr) {
        node *prev = curr->prev;
        node *next = curr->next;

        delete curr;

        prev->next = next;
        next->prev = prev;

        return next;
    }

    bool check_m(int m) {
        node *curr = start;

        int nowNode = n;

        while(curr->serial_num != 13) {
            curr = remove(curr);
            --nowNode;

            int cnt = m-1;
            while(cnt--)            // loop (m-1) times;
                curr = curr->next;
        }

        return nowNode == 1;
    }
};

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int n;

    while(scanf("%d", &n), n) {
        if(n == 13) {
            puts("1");
            continue;
        }

        for(int m = 1; true; ++m) {
            circular_list ob(n);

            if(ob.check_m(m)) {
                printf("%d\n", m);
                break;
            }
        }
    }

    return 0;
}
