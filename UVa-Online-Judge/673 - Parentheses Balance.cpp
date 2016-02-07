#include <cstdio>
#include <stack>
using namespace std;

int main()
{
    //freopen("in", "r", stdin);

    int tc;

    scanf("%d", &tc);
    getchar();

    while(tc--) {
        char str[150];
        bool isCorrect = true;
        stack<char> st;

        gets(str);

        for(int i = 0; str[i] && isCorrect; ++i) {
            char& ch = str[i];

            if(ch == '(' || ch == '[') st.push(ch);
            else if(ch == ')') {
                if(st.size() && st.top() == '(') st.pop();
                else isCorrect = false;
            }
            else if(ch == ']') {
                if(st.size() && st.top() == '[') st.pop();
                else isCorrect = false;
            }
        }

        (isCorrect && st.empty())? puts("Yes") : puts("No");
    }

    return 0;
}
