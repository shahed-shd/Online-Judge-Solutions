#include <cstdio>
#include <map>
#include <string>
#include <climits>
#include <cstring>
using namespace std;

const int MAXW = 50000+3;

map<string, int> str_int;
int allWords[MAXW];
int wordCnt, uniqueWordCnt;

int get_id(const string  word)
{
    int id = str_int[word];

    if(!id) str_int[word] = id = ++uniqueWordCnt;

    return id;
}

void input()
{
    char str[110];
    string tmp;
    wordCnt = uniqueWordCnt = 0;

    while(gets(str), strcmp(str, "END")) {
        int len = strlen(str);

        for(int i = 0; i < len; ++i) {
            while('a' <= str[i] && str[i] <= 'z')
               tmp.push_back(str[i++]);

            if(!tmp.empty()) {
                allWords[++wordCnt] = get_id(tmp);
                tmp.clear();
            }
        }
    }
}

void solve()
{
    int p = 1, q = INT_MAX;
    int counter_of[MAXW] = {0};
    int start = 1, finish = 0, cnt = 0;

    while(finish < wordCnt) {
        while(cnt < uniqueWordCnt && finish < wordCnt)
            if(++counter_of[allWords[++finish]] == 1) ++cnt;

        while(counter_of[allWords[start]] > 1)
            --counter_of[allWords[start++]];

        if(cnt == uniqueWordCnt && finish - start < q - p)
            p = start, q = finish;

        --counter_of[allWords[start++]];
        --cnt;
    }

    printf("%d %d\n", p, q);
}

int main()
{
    //freopen("in", "r", stdin);

    int t;
    scanf("%d\n", &t);

    for(int tc = 1; tc <= t; ++tc) {
        str_int.clear();
        input();
        printf("Case %d: ", tc);
        solve();
    }

    return 0;
}
