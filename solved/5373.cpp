// 시뮬레이션 플래5 큐빙 https://www.acmicpc.net/problem/5373
#include <iostream>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

enum Direction {
    UP,
    DOWN,
    FRONT,
    BACK,
    LEFT,
    RIGHT
};

enum Edges {
    ED_UP,
    ED_UP_REV,
    ED_RIGHT,
    ED_RIGHT_REV,
    ED_DOWN,
    ED_DOWN_REV,
    ED_LEFT,
    ED_LEFT_REV
};

int dirsCase[6][4] = {
    {FRONT, LEFT, BACK, RIGHT},
    {FRONT, RIGHT, BACK, LEFT},
    {UP, RIGHT, DOWN, LEFT},
    {UP, LEFT, DOWN, RIGHT},
    {UP, FRONT, DOWN, BACK},
    {UP, BACK, DOWN, FRONT}
};

int edgeCase[8][3] = {
    {0, 1, 2}, 
    {2, 1, 0},
    {2, 5, 8}, 
    {8, 5, 2},
    {6, 7, 8}, 
    {8, 7, 6},
    {0, 3, 6}, 
    {6, 3, 0}
};

char rot[256];
char cube[2][6][9];
int dirs[1001];
bool signs[1001];

int main() {
    fastio;

    rot['U'] = UP;
    rot['D'] = DOWN;
    rot['F'] = FRONT;
    rot['B'] = BACK;
    rot['L'] = LEFT;
    rot['R'] = RIGHT;
    
    int testCase; cin >> testCase;

    for (int i = 0; i < testCase; i++) {
        bool flag = true;
        int n; cin >> n;   

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 2; j++) {
                cube[j][UP][i]      = 'w';
                cube[j][DOWN][i]    = 'y';
                cube[j][FRONT][i]   = 'r';
                cube[j][BACK][i]    = 'o';
                cube[j][LEFT][i]    = 'g';
                cube[j][RIGHT][i]   = 'b';
            }
        }

        for (int i = 0; i < n; i++) {
            char s[3]; cin >> s;

            dirs[i] = rot[(int) s[0]];
            signs[i] = s[1] == '+';
        }

        for (int i = 0; i < n; i++) {
            int sign = signs[i];
            int dir = dirs[i];

            //printf("%d\n", dir);

            for (int i = 0; i < 9; i++) {
                if (sign)   cube[flag][dir][i] = cube[!flag][dir][6 - ((i % 3) * 3) + i / 3];
                else        cube[flag][dir][i] = cube[!flag][dir][3 * (i % 3) + (2 - (i / 3))];
            }

            for (int i = 0; i < 9; i++) 
                cube[!flag][dir][i] = cube[flag][dir][i];

            int edges[4];

            switch(dir) {
                case UP:
                    edges[0] = ED_UP; edges[1] = ED_UP; edges[2] = ED_UP; edges[3] = ED_UP;
                    break;

                case DOWN:
                    edges[0] = ED_DOWN; edges[1] = ED_DOWN; edges[2] = ED_DOWN; edges[3] = ED_DOWN;
                    break;

                case FRONT:
                    edges[0] = ED_DOWN; edges[1] = ED_LEFT; edges[2] = ED_DOWN; edges[3] = ED_RIGHT_REV;
                    break;

                case BACK:
                    edges[0] = ED_UP_REV; edges[1] = ED_LEFT; edges[2] = ED_UP_REV; edges[3] = ED_RIGHT_REV;
                    break;

                case LEFT:
                    edges[0] = ED_LEFT; edges[1] = ED_LEFT; edges[2] = ED_RIGHT_REV; edges[3] = ED_RIGHT_REV;
                    break;

                case RIGHT:
                    edges[0] = ED_RIGHT_REV; edges[1] = ED_LEFT; edges[2] = ED_LEFT; edges[3] = ED_RIGHT_REV;
                    break;
            }

            for (int i = 0; i < 4; i++) {
                int next = (i + (sign ? -1 : 1)) % 4;
                if (next < 0) next += 4;

                int target = dirsCase[dir][i];
                int source = dirsCase[dir][next];

                //printf("%d, %d -> %d\n", next, source, target);

                for (int j = 0; j < 3; j++) 
                    cube[flag][target][edgeCase[edges[i]][j]] = cube[!flag][source][edgeCase[edges[next]][j]];
            }

            for (int i = 0; i < 4; i++) {
                int target = dirsCase[dir][i];

                for (int j = 0; j < 3; j++) 
                    cube[!flag][target][edgeCase[edges[i]][j]] = cube[flag][target][edgeCase[edges[i]][j]];
            }

            flag = !flag;
        }

        for (int i = 0; i < 3; i++) 
            printf("%c%c%c\n", cube[flag][UP][i * 3], cube[flag][UP][i * 3 + 1], cube[flag][UP][i * 3 + 2]);
    }
}

// void print() {
//     for (int i = 0; i < 3; i++) 
//         printf("%c%c%c\n", cube[flag][UP][i * 3], cube[flag][UP][i * 3 + 1], cube[flag][UP][i * 3 + 2]);

//     // for (int i = 0; i < 3; i++) 
//     //     printf("%c%c%c\n", cube[flag][1][i * 3], cube[flag][1][i * 3 + 1], cube[flag][1][i * 3 + 2]);

//     // for (int i = 0; i < 3; i++) 
//     //     printf("%c%c%c\n", cube[flag][2][i * 3], cube[flag][2][i * 3 + 1], cube[flag][2][i * 3 + 2]);

//     // for (int i = 0; i < 3; i++) 
//     //     printf("%c%c%c\n", cube[flag][3][i * 3], cube[flag][3][i * 3 + 1], cube[flag][3][i * 3 + 2]);

//     // for (int i = 0; i < 3; i++) 
//     //     printf("%c%c%c\n", cube[flag][4][i * 3], cube[flag][4][i * 3 + 1], cube[flag][4][i * 3 + 2]);

//     // for (int i = 0; i < 3; i++) 
//     //     printf("%c%c%c\n", cube[flag][5][i * 3], cube[flag][5][i * 3 + 1], cube[flag][5][i * 3 + 2]);


//     // printf("\n\n");

//     // for (int i = 0; i < 3; i++) 
//     //     printf("%c%c%c\n", cube[flag][UP][i * 3], cube[flag][UP][i * 3 + 1], cube[flag][UP][i * 3 + 2]);

//     // for (int i = 0; i < 3; i++) 
//     //     printf("%c%c%c\n", cube[flag][1][i * 3], cube[flag][1][i * 3 + 1], cube[flag][1][i * 3 + 2]);

//     // for (int i = 0; i < 3; i++) 
//     //     printf("%c%c%c\n", cube[flag][2][i * 3], cube[flag][2][i * 3 + 1], cube[flag][2][i * 3 + 2]);

//     // for (int i = 0; i < 3; i++) 
//     //     printf("%c%c%c\n", cube[flag][3][i * 3], cube[flag][3][i * 3 + 1], cube[flag][3][i * 3 + 2]);

//     // for (int i = 0; i < 3; i++) 
//     //     printf("%c%c%c\n", cube[flag][4][i * 3], cube[flag][4][i * 3 + 1], cube[flag][4][i * 3 + 2]);

//     // for (int i = 0; i < 3; i++) 
//     //     printf("%c%c%c\n", cube[flag][5][i * 3], cube[flag][5][i * 3 + 1], cube[flag][5][i * 3 + 2]);
// }
