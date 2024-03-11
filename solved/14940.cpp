// BFS 실버 1 쉬운 최단거리 https://www.acmicpc.net/problem/14940
#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

int dir[4][2] = {
    {0, 1},
    {0, -1},
    {-1, 0},
    {1, 0}
};

queue<ii> q[2];
bool e = false;
int n, m;
bool arr[1001][1001] = {0, };
int ans[1001][1001] = {0, };

int isin(int y, int x) {
    if (y >= 0 && x >= 0 && y < n && x < m) return true;
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int t; cin >> t;
            if (t) {
                if (t == 2) q[e].push(make_pair(i, j));
                else arr[i][j] = 1;
            }
        }
    }

    int cnt = 1;
    while (!q[e].empty()) {
        while (!q[e].empty()) {
            ii tmp = q[e].front();
            q[e].pop();

            for (int i = 0; i < 4; i++) {
                int ty = tmp.first + dir[i][0];
                int tx = tmp.second + dir[i][1];

                if (isin(ty, tx) && arr[ty][tx]) {
                    q[!e].push(make_pair(ty, tx));
                    arr[ty][tx] = 0;
                    ans[ty][tx] = cnt;
                }
            }

        }

        e = !e;
        cnt++;
    }



    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j]) printf("-1 ");
            else printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
}