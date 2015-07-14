#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

void pick_keywords(vector<string> &wordsToIgnore, vector<string> &titles, vector<string> &keyWords)
{
    int titles_sz, wordsToIgnore_sz;
    istringstream iss;

    titles_sz = titles.size();
    wordsToIgnore_sz = wordsToIgnore.size();

    for(int i = 0; i < titles_sz; ++i) {
        iss.str(titles[i]);
        string temp;

        while(iss >> temp) {
            int j, k, sz;
            for(j = 0; j < wordsToIgnore_sz && wordsToIgnore[j].compare(temp); ++j);   // finding if temp matches with any ignoring words or not.

            if(j == wordsToIgnore_sz) {
                sz = keyWords.size();
                for(k = 0; k < sz && keyWords[k].compare(temp); ++k);    // finding if temp matches with any other key-words or not.
                if(k == sz) keyWords.push_back(temp);
            }
        }

        iss.clear();
    }
}

void match_keywords(string keyword, string title)
{
    istringstream iss(title);
    string temp;
    int prev_tellg, cur_tellg;

    prev_tellg = iss.tellg();

    while(iss >> temp) {
        if(temp == keyword) {
            cur_tellg = iss.tellg();

            if(cur_tellg < 0) cur_tellg = title.length();

            string ans(title);

            for(int i = prev_tellg; i < cur_tellg; ++i)
                if('a' <= ans[i] && ans[i] <= 'z') ans[i] -= 32;   // Capitalizing the word.

            cout << ans << '\n';
        }

        prev_tellg = iss.tellg();
    }
}

int main()
{
    vector<string> wordsToIgnore;
    vector<string> titles;
    string str;

    while(cin >> str, str != "::")
        wordsToIgnore.push_back(str);

    cin.ignore(1, '\n');

    while(getline(cin, str)) {
        int len = str.length();

        for(int i = 0; i < len; ++i)
            if('A' <= str[i] && str[i] <= 'Z') str[i] += 32;    // converting to lower case.

        titles.push_back(str);
    }

    vector <string> keyWords;

    pick_keywords(wordsToIgnore, titles, keyWords);

    sort(keyWords.begin(), keyWords.end());

    int keyWords_sz, titles_sz;

    keyWords_sz = keyWords.size();
    titles_sz = titles.size();

    for(int i = 0; i < keyWords_sz; ++i) {
        for(int j = 0; j < titles_sz; ++j) {
            match_keywords(keyWords[i], titles[j]);
       }
    }

    return 0;
}
