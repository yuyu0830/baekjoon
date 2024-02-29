// BFS 골드 1 구슬 탈출 1 https://www.acmicpc.net/problem/13459
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
    void input(int Y, int X) {
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

int f() {
    queue<node> q;
    node tmp; tmp.input(r, b, 0);

    q.push(tmp);

    while (q.size()) {
        tmp = q.front();
        q.pop();

        pos tr = tmp.r;
        pos tb = tmp.b;
        int tc = tmp.cnt;

        int o[4] = {tr.y, tb.x, tb.y, tr.x};
        int p[4] = {tb.y, tr.x, tr.y, tb.x};

        for (int i = 0; i < 4; i++) {
            node t; t.input(tr, tb, tc + 1);

            bool e = false;
            bool r = false;

            if (o[i] < p[i]) {
                while (!map[t.r.y + dir[i][0]][t.r.x + dir[i][1]]) {
                    t.r.y += dir[i][0];
                    t.r.x += dir[i][1];
                    if (t.r == zero) {
                        t.r.x = 0;
                        t.r.y = 0;
                        r = true;
                        break;
                    }
                }
                while (!map[t.b.y + dir[i][0]][t.b.x + dir[i][1]] && !(t.b.y + dir[i][0] == t.r.y && t.b.x + dir[i][1] == t.r.x)) {
                    t.b.y += dir[i][0];
                    t.b.x += dir[i][1];
                    if (t.b == zero) {
                        e = true;
                        break;
                    }
                }
            }

            else {
                while (!map[t.b.y + dir[i][0]][t.b.x + dir[i][1]]) {
                    t.b.y += dir[i][0];
                    t.b.x += dir[i][1];
                    if (t.b == zero) {
                        e = true;
                        break;
                    }
                }
                while (!map[t.r.y + dir[i][0]][t.r.x + dir[i][1]] && !(t.r.y + dir[i][0] == t.b.y && t.r.x + dir[i][1] == t.b.x)) {
                    t.r.y += dir[i][0];
                    t.r.x += dir[i][1];
                    if (t.r == zero) {
                        r = true;
                        break;
                    };
                }
            }
            
            if (r && !e) return t.cnt;

            if ((tr == t.r && tb == t.b) || e || t.cnt == 10) continue;
            q.push(t);
        }
    }

    return -1;
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

    int k = f();

    if (k > 0) printf("1\n");
    else printf("0\n");
}