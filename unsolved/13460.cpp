#include <iostream>
#include <string>
#include <queue>

using namespace std;

int dir[4][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};

class ii{
    public:
    int x, y;
    void input(int X, int Y) {
        x = X;
        y = Y;
    }
};

class node {
    public:
    ii r, b;
    int cnt;

    void input(ii R, ii B, int _cnt) {
        b.x = B.x;
        b.y = B.y;
        r.x = R.x;
        r.y = R.y;
        cnt = _cnt;
    }
};

int n, m; 
bool map[11][11] = {0, };
ii zero;

bool isin(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < m) return 1;
    return 0;
}

int main() {
    cin >> n >> m;
    ii b, r;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++) {
            if (str[j] == '#') 
                map[i][j] = 1;
            else {
                if (str[j] == 'B') b.input(i, j);
                else if (str[j] == 'R') r.input(i, j);
                else if (str[j] == '0') zero.input(i, j);

                map[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }

    queue<node> q;
    node tmp; tmp.input(r, b, 0);
    q.push(tmp);
    while (q.size()) {
        tmp = q.back();
        q.pop();

        ii r = tmp.r;
        ii b = tmp.b;
        int cnt = tmp.cnt;

    }
}