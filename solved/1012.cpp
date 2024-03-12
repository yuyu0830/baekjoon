// dfs 실버 2 유기농 배추 https://www.acmicpc.net/problem/1012
#include <iostream>
#include <queue>
#include <string.h>

#define SIZE 51

using namespace std;

typedef pair<int, int> ii;

int arr[SIZE][SIZE] = {0, };
int dir[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}
};

bool isin(int a, int b) {
    if (a >= 0 && b >= 0) return true;
    return false;
}

int main() {
    int testCase; cin >> testCase;
    while (testCase--) {
        for (int i = 0; i < SIZE; i++) 
            memset(arr[i], 0, sizeof(int) * SIZE);
        
        int n, m, k; cin >> n >> m >> k;

        queue<ii> q;

        for (int i = 0; i < k; i++) {
            int a, b; cin >> a >> b;
            arr[a][b] = 1;
            q.push(make_pair(a, b));
        }

        int ans = 0;
        queue<ii> tq;

        while (!q.empty()) {
            ii tmp = q.front();
            q.pop();

            if (arr[tmp.first][tmp.second]) {
                tq.push(tmp);
                ans++;
                while (!tq.empty()) {
                    ii t = tq.front();
                    tq.pop();

                    for (int i = 0; i < 4; i++) {
                        int ty = t.first + dir[i][0];
                        int tx = t.second + dir[i][1];
                        if (isin(ty, tx) && arr[ty][tx]) {
                            arr[ty][tx] = 0;
                            tq.push(make_pair(ty, tx));
                        }
                    }
                }

            }
        }

        printf("%d\n", ans);
    }
}