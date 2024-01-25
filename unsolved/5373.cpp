#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum Direction {
    UP = 0,
    DOWN = 1,
    FRONT = 2,
    BACK = 3,
    RIGHT = 4,
    LEFT = 5
};

char edge[6][4] = {
    {2, 5, 3, 4},
    {3, 5, 2, 4},
    {1, 5, 0, 4},
    {0, 5, 1, 4},
    {2, 0, 3, 1},
    {2, 1, 3, 0}
};
char color[6] = { 'w', 'y', 'r', 'o', 'g', 'b' };
char rot[256];

class Cube {
    char surface[6][3][3];

public:
    void init() {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 9; j++) {
                surface[i][j / 3][j % 3] = color[i];
            }
        }
    }

    void print() {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    printf("%c", surface[i][j][k]);
                }
                printf("\n");
            }
            printf("\n");
        }
    }

    void printup() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf("%c", surface[UP][i][j]);
            }
            printf("\n");
        }
    }

    void rotate(int dir, bool flag) {
        char tmp[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (flag)
                    tmp[i][j] = surface[dir][2 - j][i];
                else
                    tmp[i][j] = surface[dir][j][2 - i];
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                surface[dir][i][j] = tmp[i][j];
            }
        }

        for (int i = 0; i < 4; i++) {
            int t = flag ? i : 3 - i;

            
        }
    }
};

void rotInit() {
    rot['U'] = UP;
    rot['D'] = DOWN;
    rot['F'] = FRONT;
    rot['B'] = BACK;
    rot['R'] = RIGHT;
    rot['L'] = LEFT;
}

void getRotation(char* str, int& dir, bool& flag) {
    dir = rot[str[0]];
    flag = str[1] == '-';
}

int main() {
    rotInit();

    int n; 
    cin >> n;
    for (int i = 0; i < n; i++) {
        Cube c;
        c.init();

        int t; 
        cin >> t;

        for (int j = 0; j < t; j++) {
            char* s; 
            cin >> s;

            int dir;
            bool flag;
            getRotation(s, dir, flag);
            c.rotate(dir, flag);
        }
        
        c.printup();
    }

    return 0;
    
}
