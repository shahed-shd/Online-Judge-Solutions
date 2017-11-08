// ==================================================
// Problem  :   887C - Solution for Cube
// Run time :   0.015 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
using namespace std;

enum Face {TOP = 0, FRONT, BOTTOM, LEFT, RIGHT, BACK};

class RubiksCube {
    int faces[6][2][2];

    void rotateOnlyFaceClockwise(int f) {
        int tmp = faces[f][0][0];
        faces[f][0][0] = faces[f][1][0];
        faces[f][1][0] = faces[f][1][1];
        faces[f][1][1] = faces[f][0][1];
        faces[f][0][1] = tmp;
    }

    void rotateSurrounded(int &a1, int &a2, int &b1, int &b2, int &c1, int &c2, int &d1, int &d2) {
        int tmp1 = d1, tmp2 = d2;

        d1 = c1, d2 = c2;
        c1 = b1, c2 = b2;
        b1 = a1, b2 = a2;
        a1 = tmp1, a2 = tmp2;
    }


public:
    RubiksCube(int arr[]) {
        int idx = 0;

        for(int f = 0; f < 6; ++f)
            for(int i = 0; i < 2; ++i)
                for(int j = 0; j < 2; ++j)
                    faces[f][i][j] = arr[idx++];
    }

    RubiksCube(const RubiksCube &rc) {
        *this = rc;
    }

    void rotateFaceClockwise(int f) {
        rotateOnlyFaceClockwise(f);

        if(f == TOP) {
            rotateSurrounded(faces[BACK][0][1], faces[BACK][0][0], faces[RIGHT][0][1], faces[RIGHT][0][0], faces[FRONT][0][1], faces[FRONT][0][0], faces[LEFT][0][1], faces[LEFT][0][0]);
        }
        else if(f == FRONT) {
            rotateSurrounded(faces[TOP][1][0], faces[TOP][1][1], faces[RIGHT][0][0], faces[RIGHT][1][0], faces[BOTTOM][0][1], faces[BOTTOM][0][0], faces[LEFT][1][1], faces[LEFT][0][1]);
        }
        else if(f == BOTTOM) {
            rotateSurrounded(faces[FRONT][1][0], faces[FRONT][1][1], faces[RIGHT][1][0], faces[RIGHT][1][1], faces[BACK][1][0], faces[BACK][1][1], faces[LEFT][1][0], faces[LEFT][1][1]);
        }
        else if(f == LEFT) {
            rotateSurrounded(faces[TOP][0][0], faces[TOP][1][0], faces[FRONT][0][0], faces[FRONT][1][0], faces[BOTTOM][0][0], faces[BOTTOM][1][0], faces[BACK][1][1], faces[BACK][0][1]);
        }
        else if(f == RIGHT) {
            rotateSurrounded(faces[TOP][1][1], faces[TOP][0][1], faces[BACK][0][0], faces[BACK][1][0], faces[BOTTOM][1][1], faces[BOTTOM][0][1], faces[FRONT][1][1], faces[FRONT][0][1]);
        }
        else {      // f == BACK
            rotateSurrounded(faces[TOP][1][0], faces[TOP][1][1], faces[LEFT][0][0], faces[LEFT][1][0], faces[BOTTOM][1][0], faces[BOTTOM][1][1], faces[RIGHT][1][1], faces[RIGHT][0][1]);
        }
    }

    void rotateFaceCounterClockwise(int f) {
        rotateFaceClockwise(f);
        rotateFaceClockwise(f);
        rotateFaceClockwise(f);
    }

    bool isSameColor() {
        int cnt = 0;

        for(int f = 0; f < 6; ++f) {
            if(faces[f][0][0] == faces[f][0][1] and faces[f][0][1] == faces[f][1][0] and faces[f][1][0] == faces[f][1][1])
                ++cnt;
            else
                break;
        }

        return (cnt == 6);
    }
};

int main()
{
    //freopen("in.txt", "r", stdin);

    int arr[30];

    for(int i = 0; i < 24; ++i) scanf("%d", arr+i);

    RubiksCube rc(arr);
    bool ans = false;

    for(int f = 0; f < 6 and !ans; ++f){
        RubiksCube a(rc), b(rc);

        a.rotateFaceClockwise(f);
        b.rotateFaceCounterClockwise(f);

        if(a.isSameColor() or b.isSameColor()) ans = true;
    }

    puts(ans? "YES" : "NO");

    return 0;
}
