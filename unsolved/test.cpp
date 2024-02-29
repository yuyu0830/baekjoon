#include <iostream>
#include <string>
#include <queue>

using namespace std;

int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};

class pos{
    public:
    int x, y;
    void input(int X, int Y) {
        x = X;
        y = Y;
    }

    bool operator==(pos &ref) {
        if (x == ref.x && y == ref.y) return true;
        return false;
    }
};

class node {
    public:
    pos r, b;
    int cnt;

    void input(pos R, pos B, int _cnt) {
        b.x = B.x;
        b.y = B.y;
        r.x = R.x;
        r.y = R.y;
        cnt = _cnt;
    }

};

int n, m; 
bool map[11][11] = {0, };
pos zero, b, r;

bool isin(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < m) return 1;
    return 0;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++) {
            if (str[j] == '#') 
                map[i][j] = 1;
            else {
                if (str[j] == 'B') b.input(i, j);
                else if (str[j] == 'R') r.input(i, j);
                else if (str[j] == 'O') zero.input(i, j);

                map[i][j] = 0;
            }
        }
    }
    

    node t; t.input(r, b, 0);
    int i = 0;
    while (true) {
        cin >> i;
        if (i == -1) return 0;

        pos tr = t.r;
        pos tb = t.b;

        int o[4] = {tr.y, tb.x, tb.y, tr.x};
        int p[4] = {tb.y, tr.x, tr.y, tb.x};

        if (o[i] < p[i]) {
            while (!map[t.r.y + dir[i][0]][t.r.x + dir[i][1]]) {
                t.r.y += dir[i][0];
                t.r.x += dir[i][1];
                if (t.r == zero) {
                    printf("RED!\n");
                    return 0;
                }
            }
            while (!map[t.b.y + dir[i][0]][t.b.x + dir[i][1]] && !(t.b.y + dir[i][0] == t.r.y && t.b.x + dir[i][1] == t.r.x)) {
                t.b.y += dir[i][0];
                t.b.x += dir[i][1];
                if (t.b == zero) {
                    printf("BLUE!\n");
                    return 0;
                }
            }
        }

        else {
            while (!map[t.b.y + dir[i][0]][t.b.x + dir[i][1]]) {
                t.b.y += dir[i][0];
                t.b.x += dir[i][1];
                if (t.b == zero) {
                    printf("BLUE!\n");
                    return 0;
                }
            }
            while (!map[t.r.y + dir[i][0]][t.r.x + dir[i][1]] && !(t.r.y + dir[i][0] == t.b.y && t.r.x + dir[i][1] == t.b.x)) {
                t.r.y += dir[i][0];
                t.r.x += dir[i][1];
                if (t.r == zero) {
                    printf("RED!\n");
                    return 0;
                };
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == t.r.y && j == t.r.x) printf("R ");
                else if (i == t.b.y && j == t.b.x) printf("B ");
                else if (i == zero.y && j == zero.x) printf("X ");
                else printf("%d ", map[i][j]);
            }
            printf("\n");
        }
        printf("\n\n");
    }
    
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         printf("%d ", map[i][j]);
    //     }
    //     printf("\n");
    // }
}