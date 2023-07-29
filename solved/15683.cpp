// 브루트포스 골드 4 감시 https://www.acmicpc.net/problem/15683
#include <iostream>
#include <queue>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#define MAX 999999999

using namespace std;

typedef struct iii {
    int x, y, type;
    iii(int X, int Y, int T) : x(X), y(Y), type(T) {};
};

int n, m;
bool arr[9][9] = { 0, };
int map[9][9] = { 0, };
int dir[4][2] = {
    {0, -1}, // top
    {1, 0},  // right
    {0, 1},  // bottom
    {-1, 0}  // left
};
vector<iii> v;

void check(int x, int y, int d, bool io) {
    int f;
    if (io) f = 1;
    else f = -1;

    map[y][x] += f;

    int tx = x;
    int ty = y;
    while (true) {
        tx += dir[d][0];
        ty += dir[d][1];
        if (ty == n || ty == -1 || tx == m || tx == -1 || arr[ty][tx]) break;
        map[ty][tx] += f;
    }
}

int countZero() {
    int ret = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (!map[i][j]) ret++;
    return ret;
}

int f() {
    if (!v.size()) return countZero();
    
    int ret = MAX;
    iii tmp = v.back();
    v.pop_back();

    switch (tmp.type) {
    case 1:
        for (int i = 0; i < 4; i++) {
            check(tmp.x, tmp.y, i, true);
            int t = f();
            if (t < ret) ret = t;
            check(tmp.x, tmp.y, i, false);
        }
        break;
    case 2:
        for (int i = 0; i < 2; i++) {
            check(tmp.x, tmp.y, i, true);
            check(tmp.x, tmp.y, i + 2, true);
            int t = f();
            if (t < ret) ret = t;
            check(tmp.x, tmp.y, i, false);
            check(tmp.x, tmp.y, i + 2, false);
        }
        break;
    case 3:
        for (int i = 0; i < 4; i++) {
            check(tmp.x, tmp.y, i, true);
            check(tmp.x, tmp.y, (i + 1) % 4, true);
            int t = f();
            if (t < ret) ret = t;
            check(tmp.x, tmp.y, i, false);
            check(tmp.x, tmp.y, (i + 1) % 4, false);
        }
        break;
    case 4:
        for (int i = 0; i < 4; i++) {
            check(tmp.x, tmp.y, i, true);
            check(tmp.x, tmp.y, (i + 1) % 4, true);
            check(tmp.x, tmp.y, (i + 2) % 4, true);
            int t = f();
            if (t < ret) ret = t;
            check(tmp.x, tmp.y, i, false);
            check(tmp.x, tmp.y, (i + 1) % 4, false);
            check(tmp.x, tmp.y, (i + 2) % 4, false);
        }
        break;
    case 5:
        for (int i = 0; i < 4; i++)
            check(tmp.x, tmp.y, i, true);
        int t = f();
        if (t < ret) ret = t;
        for (int i = 0; i < 4; i++)
            check(tmp.x, tmp.y, i, false);
        break;
    }
    
    v.push_back(tmp);
    return ret;
}

int main() {
    fastio;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int t; cin >> t;
            if (t == 6) {
                arr[i][j] = 1;
                map[i][j] = -1;
            }
            else if (t && t < 6) {
                v.push_back({ j, i, t });
            }
        }
    }

    int ans = f();
    printf("%d\n", ans);
}

