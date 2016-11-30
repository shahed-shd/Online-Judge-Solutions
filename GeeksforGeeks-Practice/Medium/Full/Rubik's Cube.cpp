// ==================================================
// Problem  :   Rubik's Cube
// Run time :   0.075 sec.
// Language :   C++11
// ==================================================

#include <cstdio>
#include <cstring>
using namespace std;

struct surface {
    char s[12];

    void take_input() {
        scanf("%s", &s[1]);
    }
};

enum face {UP = 0, FRONT, LEFT, RIGHT, BACK, DOWN};

surface surf[6];

inline void rotate_clockwish(char *s)
{
    char s2 = s[2], s3 = s[3];

    s[3] = s[1];
    s[2] = s[4];
    s[1] = s[7];
    s[4] = s[8];
    s[7] = s[9];
    s[8] = s[6];
    s[9] = s3;
    s[6] = s2;
}

inline void rotate_anti_clockwise(char *s)
{
    char s1 = s[1], s2 = s[2];

    s[1] = s[3];
    s[2] = s[6];
    s[3] = s[9];
    s[6] = s[8];
    s[9] = s[7];
    s[8] = s[4];
    s[7] = s1;
    s[4] = s2;
}

void move_R()
{
    char tmp[5];

    for(int i = 1, j = 9; i <= 3; ++i, j-=3) tmp[i] = surf[UP].s[j];

    for(int i = 9; i >= 3; i-=3) surf[UP].s[i] = surf[FRONT].s[i];

    for(int i = 3; i <= 9; i+=3) surf[FRONT].s[i] = surf[DOWN].s[i];

    for(int i = 3, j = 7; i <= 9; i+=3, j-=3) surf[DOWN].s[i] = surf[BACK].s[j];

    for(int i = 1, j = 1; i <= 3; ++i, j+=3) surf[BACK].s[j] = tmp[i];

    rotate_clockwish(surf[RIGHT].s);
}

void move_Ri()
{
    char tmp[5];

    for(int i = 1, j = 3; i <= 3; ++i, j+=3) tmp[i] = surf[UP].s[j];

    for(int i = 3, j = 7; i <= 9; i+=3, j-=3) surf[UP].s[i] = surf[BACK].s[j];

    for(int i = 3, j = 7; i <= 9; i+=3, j-=3) surf[BACK].s[j] = surf[DOWN].s[i];

    for(int i = 3; i <= 9; i+=3) surf[DOWN].s[i] = surf[FRONT].s[i];

    for(int i = 1, j = 3; i <= 3; ++i, j+=3) surf[FRONT].s[j] = tmp[i];

    rotate_anti_clockwise(surf[RIGHT].s);
}

void move_L()
{
    char tmp[5];

    for(int i = 1, j = 1; i <= 3; ++i, j+=3) tmp[i] = surf[UP].s[j];

    for(int i = 1, j = 9; i <= 7; i+=3, j-=3) surf[UP].s[i] = surf[BACK].s[j];

    for(int i = 9, j = 1; i >= 3; i-=3, j+=3) surf[BACK].s[i] = surf[DOWN].s[j];

    for(int i = 1; i <= 7; i+=3) surf[DOWN].s[i] = surf[FRONT].s[i];

    for(int i = 1, j = 1; i <= 3; ++i, j+=3) surf[FRONT].s[j] = tmp[i];

    rotate_clockwish(surf[LEFT].s);
}

void move_Li()
{
    char tmp[5];

    for(int i = 1, j = 1; i <= 3; ++i, j+=3) tmp[i] = surf[UP].s[j];

    for(int i = 1; i <= 7; i+=3) surf[UP].s[i] = surf[FRONT].s[i];

    for(int i = 1; i <= 7; i+=3) surf[FRONT].s[i] = surf[DOWN].s[i];

    for(int i = 1, j = 9; i <= 7; i+=3, j-=3) surf[DOWN].s[i] = surf[BACK].s[j];

    for(int i = 9, j = 1; i >= 3; i-=3, ++j) surf[BACK].s[i] = tmp[j];

    rotate_anti_clockwise(surf[LEFT].s);
}

void move_B()
{
    char tmp[5];

    for(int i = 1; i <= 3; ++i) tmp[i] = surf[UP].s[i];

    for(int i = 1, j = 3; i <= 3; ++i, j+=3) surf[UP].s[i] = surf[RIGHT].s[j];

    for(int i = 3, j = 9; i <= 9; i+=3, --j) surf[RIGHT].s[i] = surf[DOWN].s[j];

    for(int i = 9, j = 7; i >= 7; --i, j-=3) surf[DOWN].s[i] = surf[LEFT].s[j];

    for(int i = 7, j = 1; i >= 1; i-=3, ++j) surf[LEFT].s[i] = tmp[j];

    rotate_clockwish(surf[BACK].s);
}

void move_Bi()
{
    char tmp[5];

    for(int i = 1; i <= 3; ++i) tmp[i] = surf[UP].s[i];

    for(int i = 3, j = 1; i >= 1; --i, j+=3) surf[UP].s[i] = surf[LEFT].s[j];

    for(int i = 1, j = 7; i <= 7; i+=3, ++j) surf[LEFT].s[i] = surf[DOWN].s[j];

    for(int i = 7, j = 9; i <= 9; ++i, j-=3) surf[DOWN].s[i] = surf[RIGHT].s[j];

    for(int i = 9, j = 3; i >= 3; i-=3, --j) surf[RIGHT].s[i] = tmp[j];

    rotate_anti_clockwise(surf[BACK].s);
}

void move_D()
{
    char tmp[5];

    for(int i = 1, j = 7; i <= 3; ++i, ++j) tmp[i] = surf[FRONT].s[j];

    for(int i = 7; i <= 9; ++i) surf[FRONT].s[i] = surf[LEFT].s[i];

    for(int i = 7; i <= 9; ++i) surf[LEFT].s[i] = surf[BACK].s[i];

    for(int i = 7; i <= 9; ++i) surf[BACK].s[i] = surf[RIGHT].s[i];

    for(int i = 7, j = 1; i <= 9; ++i, ++j) surf[RIGHT].s[i] = tmp[j];

    rotate_clockwish(surf[DOWN].s);
}

void move_Di()
{
    char tmp[5];

    for(int i = 1, j = 7; i <= 3; ++i, ++j) tmp[i] = surf[FRONT].s[j];

    for(int i = 7; i <= 9; ++i) surf[FRONT].s[i] = surf[RIGHT].s[i];

    for(int i = 7; i <= 9; ++i) surf[RIGHT].s[i] = surf[BACK].s[i];

    for(int i = 7; i <= 9; ++i) surf[BACK].s[i] = surf[LEFT].s[i];

    for(int i = 7, j = 1; i <= 9; ++i, ++j) surf[LEFT].s[i] = tmp[j];

    rotate_anti_clockwise(surf[DOWN].s);
}

void move_F()
{
    char tmp[5];

    for(int i = 1, j = 7; i <= 3; ++i, ++j) tmp[i] = surf[UP].s[j];

    for(int i = 7, j = 9; i <= 9; ++i, j-=3) surf[UP].s[i] = surf[LEFT].s[j];

    for(int i = 3, j = 1; i <= 9; i+=3, ++j) surf[LEFT].s[i] = surf[DOWN].s[j];

    for(int i = 1, j = 7; i <= 3; ++i, j-=3) surf[DOWN].s[i] = surf[RIGHT].s[j];

    for(int i = 1, j = 1; i <= 7; i+=3, ++j) surf[RIGHT].s[i] = tmp[j];

    rotate_clockwish(surf[FRONT].s);
}

void move_Fi()
{
    char tmp[5];

    for(int i = 1, j = 7; i <= 3; ++i, ++j) tmp[i] = surf[UP].s[j];

    for(int i = 7, j = 1; i <= 9; ++i, j+=3) surf[UP].s[i] = surf[RIGHT].s[j];

    for(int i = 1, j = 3; i <= 7; i+=3, --j) surf[RIGHT].s[i] = surf[DOWN].s[j];

    for(int i = 1, j = 3; i <= 3; ++i, j+=3) surf[DOWN].s[i] = surf[LEFT].s[j];

    for(int i = 3, j = 3; i <= 9; i+=3, --j) surf[LEFT].s[i] = tmp[j];

    rotate_anti_clockwise(surf[FRONT].s);
}

void move_U()
{
    char tmp[5];

    for(int i = 1; i <= 3; ++i) tmp[i] = surf[FRONT].s[i];

    for(int i = 1; i <= 3; ++i) surf[FRONT].s[i] = surf[RIGHT].s[i];

    for(int i = 1; i <= 3; ++i) surf[RIGHT].s[i] = surf[BACK].s[i];

    for(int i = 1; i <= 3; ++i) surf[BACK].s[i] = surf[LEFT].s[i];

    for(int i = 1; i <= 3; ++i) surf[LEFT].s[i] = tmp[i];

    rotate_clockwish(surf[UP].s);
}

void move_Ui()
{
    char tmp[5];

    for(int i = 1; i <= 3; ++i) tmp[i] = surf[FRONT].s[i];

    for(int i = 1; i <= 3; ++i) surf[FRONT].s[i] = surf[LEFT].s[i];

    for(int i = 1; i <= 3; ++i) surf[LEFT].s[i] = surf[BACK].s[i];

    for(int i = 1; i <= 3; ++i) surf[BACK].s[i] = surf[RIGHT].s[i];

    for(int i = 1; i <= 3; ++i) surf[RIGHT].s[i] = tmp[i];

    rotate_anti_clockwise(surf[UP].s);
}

void output()
{
    puts("UP");
    puts(surf[UP].s+1);

    puts("FRONT");
    puts(surf[FRONT].s+1);

    puts("LEFT");
    puts(surf[LEFT].s+1);

    puts("RIGHT");
    puts(surf[RIGHT].s+1);

    puts("BACK");
    puts(surf[BACK].s+1);

    puts("DOWN");
    puts(surf[DOWN].s+1);
}

int main()
{
    //freopen("in", "r", stdin);
    //freopen("out", "w", stdout);

    int t;
    scanf("%d", &t);

    while(t--) {
        for(int i = 0; i < 6; ++i) {
            scanf("%*s");
            surf[i].take_input();
        }

        int mv;
        scanf("%d", &mv);
        char str[5];

        while(mv--) {
            scanf("%s", str);

            if(!strcmp(str, "R")) move_R();
            else if(!strcmp(str, "Ri")) move_Ri();
            else if(!strcmp(str, "L")) move_L();
            else if(!strcmp(str, "Li")) move_Li();
            else if(!strcmp(str, "B")) move_B();
            else if(!strcmp(str, "Bi")) move_Bi();
            else if(!strcmp(str, "D")) move_D();
            else if(!strcmp(str, "Di")) move_Di();
            else if(!strcmp(str, "F")) move_F();
            else if(!strcmp(str, "Fi")) move_Fi();
            else if(!strcmp(str, "U")) move_U();
            else move_Ui();
        }

        output();
    }

    return 0;
}
