#include <iostream>
using namespace std;

void finding(string& w1, string& w2, int& p1, int& p2)
{
    int sz = w1.length();

    for(int i = 0; i < sz; ++i) {
        size_t k = w2.find(w1[i]);

        if(k != string::npos) {
            p1 = i;
            p2 = k;
            break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);

    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    string word1;
    bool newline = false;

    while(cin >> word1, word1 != "#") {
        string word2, word3, word4;
        cin >> word2 >> word3 >> word4;

        int p1, p2, p3, p4;
        p1 = p2 = p3 = p4 = -1;

        finding(word1, word2, p1, p2);
        finding(word3, word4, p3, p4);

        if(newline) cout << '\n';
        newline = true;

        if(p1 < 0 || p2 < 0 || p3 < 0 || p4 < 0) {
            cout << "Unable to make two crosses\n";
            continue;
        }

        string vWord1, vWord2;

        int diff_p2_p4 = p2 - p4;

        if(diff_p2_p4 > 0) {
            vWord1 = word2;
            vWord2 = string(diff_p2_p4, ' ') + word4;
        }
        else if(diff_p2_p4 < 0) {
            vWord1 = string(-diff_p2_p4, ' ') + word2;
            vWord2 = word4;
        }
        else {
            vWord1 = word2;
            vWord2 = word4;
        }

        unsigned hLine = max(p2, p4);

        // Before the horizontal line.
        for(unsigned h = 0; h < hLine; ++h) {
            if(vWord1[h] != ' ' && vWord2[h] == ' ')
                cout << string(p1, ' ') << vWord1[h] << '\n';

            else if(vWord1[h] != ' ' && vWord2[h] != ' ')
                cout << string(p1, ' ') << vWord1[h] << string(word1.length()-p1-1+3+p3, ' ') << vWord2[h] << '\n';

            else if(vWord1[h] == ' ' && vWord2[h] != ' ')
                cout << string(word1.length()+3+p3, ' ') << vWord2[h] << '\n';
        }

        // The horizontal line.
        cout << word1 << "   " << word3 << '\n';

        // Now, after the horizontal line.
        unsigned vLen = max(vWord1.length(), vWord2.length());

        for(unsigned h = hLine+1; h < vLen; ++h) {
            if(vWord1.length() >= h+1 && vWord2.length() < h+1)
                cout << string(p1, ' ') << vWord1[h] << '\n';

            else if(vWord1.length() >= h+1 && vWord2.length() >= h+1)
                cout << string(p1, ' ') << vWord1[h] << string(word1.length()-p1-1+3+p3, ' ') << vWord2[h] << '\n';

            else if(vWord1.length() < h+1 && vWord2.length() >= h+1)
                cout << string(word1.length()+3+p3, ' ') << vWord2[h] << '\n';
        }
    }

    return 0;
}
