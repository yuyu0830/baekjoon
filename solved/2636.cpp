// BFS 골드 4 치즈 https://www.acmicpc.net/problem/2636
#include <iostream>
#include <vector>
#include <math.h>
#include <cstring>
#include <algorithm>

#define MAX 999999999
#define NUM 101
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;
using ii = pair<int, int>;

int n, m, cnt = 0, ans = 0, last = 0;
bool arr[NUM][NUM] = { 0, };
bool e[NUM][NUM] = { 0, };
vector<ii> v[2];
bool flag = false;

int dir[4][2] = {
	{0, 1},
	{0, -1},
	{1, 0},
	{-1, 0}
};

bool isin(int x, int y) {
	if ((x < 0 || x >= m) || (y < 0 || y >= n)) return false;
	return true;
}

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			bool t; cin >> t;
			if (t) cnt++;
			arr[i][j] = t;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j : {0, m - 1}) {
			v[flag].emplace_back(i, j);
			e[i][j] = true;
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j : {0, n - 1}) {
			v[flag].emplace_back(j, i);
			e[j][i] = true;
		}
	}
}

void f() {
	while (cnt) {
		ans++;
		last = cnt;
		while (v[flag].size()) {
			ii tmp = v[flag].back();
			v[flag].pop_back();
			
			for (int d = 0; d < 4; d++) {
				int y = tmp.first + dir[d][0];
				int x = tmp.second + dir[d][1];
				if (isin(x, y) && !e[y][x]) {
					e[y][x] = true;
					if (arr[y][x]) v[!flag].emplace_back(y, x);
					else v[flag].emplace_back(y, x);
				}
			}
		}
		for (ii tmp : v[!flag]) {
			arr[tmp.first][tmp.second] = false;
			cnt--;
		}
		flag = !flag;
	}
	printf("%d\n%d\n", ans, last);
}

int main() {
	input();
	f();
}

