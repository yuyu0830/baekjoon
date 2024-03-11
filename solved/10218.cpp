// BFS 플레5 MAZE https://www.acmicpc.net/problem/10218
#include <iostream>
#include <string>
#include <string.h>
#include <queue>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define SIZE 12

using namespace std;

int dir[4][2] = {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};

char dStr[4] = {'U', 'R', 'D', 'L'};

int n, m; 

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
    bool board[SIZE][SIZE];

    node() {
        this->cnt = 0;
        this->rnd = 0;
        this->lastDir = -1;
        this->s = "";
        for (int i = 0; i < ::n; i++) 
            memset(board[i], 0, sizeof(int) * SIZE);
    }

    node(vector<pos> _v, int _cnt, int _rnd, string _s, bool _board[SIZE][SIZE]) {
        this->v = _v;
        this->cnt = _cnt;
        this->rnd = _rnd;
        this->lastDir = -1;
        this->s = _s;
        for (int i = 0; i < ::n; i++) 
            for (int j = 0; j < ::m; j++) 
                this->board[i][j] = _board[i][j];
    }

    node(const node& n) {
        this->v = n.v;
        this->cnt = n.cnt;
        this->rnd = n.rnd;
        this->lastDir = n.lastDir;
        this->s = n.s;
        for (int i = 0; i < ::n; i++) 
            for (int j = 0; j < ::m; j++) 
                this->board[i][j] = n.board[i][j];
    }

    void addDir(int dir) {
        s.push_back(dStr[dir]);
        lastDir = dir;
    }

    void operator= (const node& n) {
        this->v = n.v;
        this->cnt = n.cnt;
        this->rnd = n.rnd;
        this->lastDir = n.lastDir;
        this->s = n.s;
        for (int i = 0; i < ::n; i++)
            for (int j = 0; j < ::m; j++)
                this->board[i][j] = n.board[i][j];
    }
};

string f() {
    cin >> n >> m;

    node first;

    bool map[n][m];

    pos zero;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++) {
            if (str[j] == '#') {
                map[i][j] = 1;
                continue;
            }

            if (str[j] == 'O') {
                zero.input(i, j);
                continue;
            }

            first.cnt++;
            first.v.push_back({i, j});
            first.board[i][j] = 1;
            map[i][j] = 0;   
        }
    }

    queue<node> q;
    q.push(first);

    while (q.size()) {
        node tmp = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            if (i != -1)
                if ((i % 2) == (tmp.lastDir % 2)) continue;

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

                t.board[p.y][p.x] = 0;

                if (zero.y == ty && zero.x == tx) {
                    t.cnt--;
                    continue;
                }

                if (map[ty][tx]) {
                    t.board[p.y][p.x] = 1;
                    tv.push_back({p.y, p.x});
                    continue;
                }
                
                while (!map[ty][tx]) {
                    if (t.board[ty][tx]) {
                        t.cnt--;
                        break;
                    }

                    if (zero.y == ty && zero.x == tx) {
                        t.cnt--;
                        break;
                    }

                    if (map[ty + dir[i][0]][tx + dir[i][1]]) {
                        t.board[ty][tx] = 1;
                        tv.push_back({ty, tx});
                    }

                    ty += dir[i][0]; 
                    tx += dir[i][1];
                }
            }

            if (!t.cnt) {
                t.addDir(i);
                return t.s;
            }

            
            if (t.rnd != 9 && !tv.empty()) {
                t.v = tv;
                t.addDir(i);
                t.rnd += 1;
                t.lastDir = i;
                q.push(t);
            }
        }
    }

    return "";
}

int main() {
    fastio;
    int testCase; cin >> testCase;
    while (testCase--) {
        string ans = f();
        if (ans.length()) 
            printf("%s\n", ans.c_str());
        
        else 
            printf("XHAE\n");
    }
}