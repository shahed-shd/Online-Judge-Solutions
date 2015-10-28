#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#define     cationMatrix(i,j)   (*(cationMatrix+na*i+j))
#define     anionMatrix(i,j)    (*(anionMatrix+nc*i+j))
#define     matrix(i,j)         (*(matrix+compound*i+j))

int compound;
int *matrix;
vector<pair<string,bool> > newCationList;  // cation, isFree
vector<pair<string,int> > newAnionList;    // anion, anionMathesWith

bool isMorePreferable(int anion, int cation, int cation1)
{
    anion += compound;

    for(int i = compound-1; i >= 0; --i) {
        if(matrix(anion, i) == cation) return true;
        if(matrix(anion, i) == cation1) return false;
    }
    return false;
}

void stableMatching()
{
    int freeCount = compound;

    while(freeCount) {
        int freeCation;
        for(freeCation = 0; freeCation < compound; ++freeCation)
            if(newCationList[freeCation].second == true) break;

        for(int i = compound-1; i >= 0 && newCationList[freeCation].second; --i) {
            int targetAnion = matrix(freeCation, i);

            if(newAnionList[targetAnion].second ==  -1) {
                newAnionList[targetAnion].second = freeCation;
                newCationList[freeCation].second = false;
                --freeCount;
            }
            else {
                int cation2 = newAnionList[targetAnion].second;

                if(isMorePreferable(targetAnion, freeCation, cation2)) {
                    newAnionList[targetAnion].second = freeCation;
                    newCationList[freeCation].second = false;
                    newCationList[cation2].second = true;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);

    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int scenerio = 0, nc;

    while(cin >> nc, nc != 0) {
        vector<string> cationList, anionList;
        string str;

        for(int i = 0; i < nc; ++i) {
            cin >> str;
            cationList.push_back(str);
        }

        int na;
        cin >> na;

        for(int i = 0; i < na; ++i) {
            cin >> str;
            anionList.push_back(str);
        }

        int *cationMatrix, *anionMatrix;

        cationMatrix = new int [nc*na];
        anionMatrix = new int [na*nc];

        int temp;

        for(int i = 0; i < nc; ++i) {
            for(int j = 0; j < na; ++j) {
                cin >> temp;
                cationMatrix(i, temp-1) = j;
            }
        }

        for(int i = 0; i < na; ++i) {
            for(int j = 0; j < nc; ++j) {
                cin >> temp;
                anionMatrix(i, temp-1) = j;
            }
        }

        ++scenerio;
        int mixture = 0;

        while(cin >> compound, compound != 0) {
            newCationList.clear();
            newAnionList.clear();

            unordered_map<string,int> cationCount, anionCount;

            for(int i = 0; i < compound; ++i) {
                cin >> str;
                ++cationCount[str.substr(0, 2)];
                ++anionCount[str.substr(2, 2)];
            }

            for(int i = 0; i < nc; ++i) {       // forming newCationList.
                str = cationList[i];
                temp = cationCount[str];
                while(temp--)
                    newCationList.push_back(make_pair(str, true));
            }

            for(int i = 0; i < na; ++i) {       // forming newAnionList.
                str = anionList[i];
                temp = anionCount[str];
                while(temp--)
                    newAnionList.push_back(make_pair(str, -1));
            }

            // Now, forming matrix.

            matrix = new int [2*compound*compound];
            int times, r,c;

            r = 0;
            for(int i = 0; i < nc; ++i) {
                int t = cationCount[cationList[i]];

                while(t--) {
                    c = 0;
                    for(int j = 0; j < na; ++j) {
                        str = anionList[cationMatrix(i,j)];

                        for(temp = 0; temp < compound; ++temp)
                            if(newAnionList[temp].first == str) break;

                        times = anionCount[str];

                        while(times--)
                            matrix(r,c++) = temp++;
                    }
                    ++r;
                }
            }

            for(int i = 0; i < na; ++i) {
                int t = anionCount[anionList[i]];

                while(t--) {
                    c = 0;
                    for(int j = 0; j < nc; ++j) {
                        str = cationList[anionMatrix(i,j)];

                        for(temp = 0; temp < compound; ++temp)
                            if(newCationList[temp].first == str) break;

                        times = cationCount[str];

                        while(times--)
                            matrix(r,c++) = temp++;
                    }
                    ++r;
                }
            }

            // matrix forming complete.

            stableMatching();

            if(scenerio > 1 || mixture) cout << '\n';
            cout << "Scenario " << scenerio << ", Mixture " << ++mixture << ":\n";

            for(int i = 0; i < compound; ++i) {
                if(i) cout << ' ';
                cout << newCationList[newAnionList[i].second].first << newAnionList[i].first;
            }
            cout << '\n';

            delete [] matrix;
        }

        delete [] cationMatrix;
        delete [] anionMatrix;
    }

    return 0;
}
