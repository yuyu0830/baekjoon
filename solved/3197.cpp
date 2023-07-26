//탐색 플레 5 백조의 호수 https://www.acmicpc.net/problem/3197
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX 1501

using namespace std;
typedef struct ii {
    int x, y;
    ii(int X, int Y) : x(X), y(Y) {}
};

typedef struct iib {
    int x, y;
    bool e;
    iib(ii XY, bool E) : x(XY.x), y(XY.y), e(E) {}
};

bool e[MAX][MAX];
bool arr[MAX][MAX];
short map[MAX][MAX] = { 0, };
bool bmap[MAX][MAX] = { 0, };

bool isin(int t, int a, int b);

int main() {
    fastio;

    char a;
    int n, m;
    int ans = 0;
    int p[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    cin >> n >> m;

    queue<ii> waterq[2];
    queue<iib> tq[2];

    bool waterFlag = false;
    bool tqFlag = false;
    bool startFlag = false;

    ii start = { -1, -1 };
    ii end = { -1, -1 };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a;
            if (a == 'X') {
                arr[i][j] = 1;
            }
            else {
                arr[i][j] = 0;
                waterq[waterFlag].push({i, j});
                if (a == 'L') {
                    if (!startFlag) {
                        start = { i, j };
                        startFlag = true;
                    }
                    else {
                        end = { i, j };
                    }
                }
            }
        }
    }
 
    // loop
    tq[tqFlag].push({ start, false });
    tq[tqFlag].push({ end, true });

    bool endFlag = false;

    while (true) {
        // 만날 수 있으면 바로 끝
        while (tq[tqFlag].size()) {
            iib tmp = tq[tqFlag].front();
            tq[tqFlag].pop();

            if (!bmap[tmp.x][tmp.y]) {
                tq[!tqFlag].push(tmp);
                bmap[tmp.x][tmp.y] = true;
            }

            for (int dir = 0; dir < 4; dir++) {
                int x = tmp.x + p[dir][0];
                int y = tmp.y + p[dir][1];
                int se = tmp.e + 1;

                if (isin(x, 0, n) && isin(y, 0, m)) {
                    if (!map[x][y]) {
                        if (!arr[x][y]) {
                            map[x][y] = se;
                            tq[tqFlag].push({ { x, y } , tmp.e });
                        }
                    }
                    else {
                        if (map[x][y] != se) {
                            endFlag = true;
                            break;
                        }
                    }
                }
            }
        }

        if (endFlag) break;

        // 얼음 하루 녹이기
        while (waterq[waterFlag].size()) {
            ii tmp = waterq[waterFlag].front();
            waterq[waterFlag].pop();
            for (int dir = 0; dir < 4; dir++) {
                int x = tmp.x + p[dir][0];
                int y = tmp.y + p[dir][1];
                if (isin(x, 0, n) && isin(y, 0, m) && !e[x][y] && arr[x][y]) {
                    arr[x][y] = false;
                    e[x][y] = true;
                    waterq[!waterFlag].push({ x, y });
                }
            }
        }

        tqFlag = !tqFlag;
        waterFlag = !waterFlag;
        ans++;
    }
    printf("%d\n", ans);
}

bool isin(int t, int a, int b) {
    if (t >= a && t < b) return true;
    return false;
}
