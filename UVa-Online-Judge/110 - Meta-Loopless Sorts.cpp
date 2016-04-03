#include <cstdio>
#include <string>
using namespace std;

int n;

void backtrack(int idx, string str)
{
    if(idx == n) {
        printf("%swriteln(", string(idx*2, ' ').c_str());

        for(int i = 0; i < idx-1; ++i)
            printf("%c,", str[i]);

        printf("%c)\n", str[idx-1]);

        return;
    }

    string tmpStr;

    for(int i = idx-1; i >= 0; --i) {
        printf("%s", string(idx*2, ' ').c_str());

        if(i != idx-1) printf("else ");
        printf("if %c < %c then\n", str[i], 'a'+idx);

        tmpStr = str;

        if(i+1 > idx-1) tmpStr.push_back('a'+idx);
        else tmpStr.insert(i+1, 1, 'a'+idx);

        backtrack(idx+1, tmpStr);
    }

    printf("%s", string(idx*2, ' ').c_str());

    puts("else");
    backtrack(idx+1, char('a'+idx) + str);
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int tc;
    scanf("%d", &tc);

    while(tc--) {
        scanf("%d", &n);

        puts("program sort(input,output);\nvar");

        for(int i = 0; i < n-1; ++i)
            printf("%c,", 'a'+i);

        printf("%c : integer;\nbegin\n  readln(", 'a'+n-1);

        for(int i = 0; i < n-1; ++i)
            printf("%c,", 'a'+i);

        printf("%c);\n", 'a'+n-1);

        backtrack(1, string("a"));

        puts("end.");

        if(tc) putchar('\n');
    }

    return 0;
}
