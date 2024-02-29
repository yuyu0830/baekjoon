#include <iostream>
#include <string>
#include <string.h>
#include <queue>

using namespace std;

int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};

int optDir[2][2][2] = {
    {{0, -1}, {0, 1}},
    {{-1, 0}, {1, 0}},
};

int n, m, total = 0; 
bool map[11][11] = {0, };
bool board[11][11] = {0, };
bool visited[11][11] = {0, };

class pos{
    public:
    int y, x;
    void input(int Y, int X) {
        y = Y;
        x = X;
    }

    bool operator==(pos &ref) {
        if (x == ref.x && y == ref.y) return true;
        return false;
    }

    pos() {};

    pos(int Y, int X) : y(Y), x(X) {};
};

class node {
public:
    vector<pos> v;
    int rnd, cnt, lastDir;
    string s;
    bool board[11][11];

    node(vector<pos> _v, int _cnt, int _rnd, string _s, bool _board[11][11]) {
        this->v = _v;
        this->cnt = _cnt;
        this->rnd = _rnd;
        this->lastDir = -1;
        this->s = _s;
        for (int i = 0; i < ::n; i++) {
            for (int j = 0; j < ::m; j++) {
                this->board[i][j] = _board[i][j];
            }
        }
    }

    node(const node& n) {
        this->v = n.v;
        this->cnt = n.cnt;
        this->rnd = n.rnd + 1;
        this->lastDir = n.lastDir;
        this->s = n.s;
        for (int i = 0; i < ::n; i++) {
            for (int j = 0; j < ::m; j++) {
                this->board[i][j] = n.board[i][j];
            }
        }
    }
};

pos zero;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++) {
            if (str[j] == '#') {
                map[i][j] = 1;
                board[i][j] = 1;
            }   
            else {
                if (str[j] == 'O') zero.input(i, j);
                map[i][j] = 0;
                total += 1;
            }
        }
    }

    bool e = false;
    vector<pos> tv[2];

    tv[e].push_back(zero);
    tv[e].push_back({1, 3});

    int cnt = 0;
    int ccccc = 1;
    int i = 0; cin >> i;

    while (!tv[e].empty()) { // move all gusul
        pos p = tv[e].back();
        tv[e].pop_back();

        int ty = p.y + dir[i][0];
        int tx = p.x + dir[i][1];

        while (!map[ty][tx]) {
            p.y += dir[i][0];
            p.x += dir[i][1];

            if (!board[ty][tx]) {
                board[ty][tx] = true;
                cnt += 1;
            }

            int ty1 = p.y + optDir[i % 2][0][0];
            int tx1 = p.x + optDir[i % 2][0][1];
            int ty2 = p.y + optDir[i % 2][1][0];
            int tx2 = p.x + optDir[i % 2][1][1];
            printf("%d, %d\n", p.y, p.x);
            printf("!! %d, %d  :  %d, %d\n", ty1, tx1, ty2, tx2);
            printf("!! %d      :  %d\n", map[ty1][tx1], map[ty2][tx2]);

            if (map[ty1][tx1] ^ map[ty2][tx2]) {
                if (!visited[ty][tx]){
                    visited[ty][tx] = 1;
                    tv[!e].push_back({ty, tx}); 
                }
            }

            ty += dir[i][0];
            tx += dir[i][1];
        }
    }

    if (cnt == ::total) printf("!!!!\n");

    e = !e;

    printf("%d : \n", ccccc++);

    for (pos p : tv[e]) {
        printf("%d, %d\n", p.y, p.x);
    }
    printf("\n\n\n\n");

    
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         printf("%d ", map[i][j]);
    //     }
    //     printf("\n");
    // }
}