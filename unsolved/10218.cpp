// BFS 골드 1 구슬 탈출 3 https://www.acmicpc.net/problem/13644
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
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

char dStr[4] = {'D', 'L', 'U', 'R'};

int n, m, total; 
bool map[11][11] = {0, };
pos zero;
bool visited[11][11] = {0, };

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

    void addDir(int dir) {
        s.push_back(dStr[dir]);
        lastDir = dir;
    }
};

node f() {
    queue<node> q;
    
    vector<pos> tmpv;
    tmpv.push_back(zero);

    node tmp(tmpv, 0, 0, "", map);

    q.push(tmp);

    while (q.size()) {
        tmp = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            if (i != -1 && i == (tmp.lastDir + 2) % 4) continue;

            bool e = true;

            for (pos p : tmp.v) { // check movable
                if (!map[p.y + dir[i][0]][p.x + dir[i][1]]) {
                    e = false;
                    break;
                }
            }

            if (e) continue; // continue when can't move

            vector<pos> tv;
            node t(tmp);

            while (!t.v.empty()) { // move all gusul
                pos p = t.v.back();
                t.v.pop_back();

                int ty = p.y + dir[i][0];
                int tx = p.x + dir[i][1];

                while (!map[ty][tx]) {
                    p.y += dir[i][0];
                    p.x += dir[i][1];
                    if (!t.board[ty][tx]) {
                        t.board[ty][tx] = true;
                        t.cnt += 1;
                    }

                    int ty1 = p.y + optDir[i % 2][0][0];
                    int tx1 = p.x + optDir[i % 2][0][1];
                    int ty2 = p.y + optDir[i % 2][1][0];
                    int tx2 = p.x + optDir[i % 2][1][1];

                    if (map[ty1][tx1] ^ map[ty2][tx2]) {
                        if (!visited[ty][tx]){
                            visited[ty][tx] = 1;
                            tv.push_back({ty, tx}); 
                        }
                    }

                    ty += dir[i][0];
                    tx += dir[i][1];
                }
            }

            if (t.cnt == ::total) return t;

            if (t.rnd != 10) {
                t.v = tv;
                t.addDir(i);
                q.push(t);
            }
        }
    }

    tmp.cnt = 0;
    tmp.s = "";

    return tmp;
}

int main() {
    int testCase; cin >> testCase;
    while (testCase--) {
        total = 0;

        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;
            for (int j = 0; j < m; j++) {
                if (str[j] == '#') 
                    map[i][j] = 1;
                else {
                    if (str[j] == 'O') zero.input(i, j);
                    map[i][j] = 0;
                    total += 1;
                }
            }
        }

        node ans = f();
        if (ans.cnt) printf("%s\n", ans.s.c_str());
        else printf("XHAE\n");
    }
}