// DP 골드 4 내리막길 https://www.acmicpc.net/problem/1520
#include <iostream>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX 999999999

using namespace std;

int n, m;
int arr[501][501] = { 0, };
int dp[501][501] = { 0, };
bool map[501][501] = { 0, };
bool e[501][501] = { 0, };
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

int f(int x, int y) {
	if (x == (m - 1) && y == (n - 1)) return 1;
	if (e[y][x]) return dp[y][x];
	e[y][x] = true;

	int ret = 0;

	for (int i = 0; i < 4; i++) {
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		if (tx >= 0 && tx < m && ty >= 0 && ty < n) {
			if (!map[ty][tx] && arr[y][x] > arr[ty][tx]) {
				map[ty][tx] = true;
				dp[ty][tx] = f(tx, ty);
				ret += dp[ty][tx];
				map[ty][tx] = false;
			}
		}
	}

	return ret;
}

int main() {
	fastio;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	int ans = f(0, 0);
	printf("%d\n", ans);
}