#include <iostream>

#define NUM 129

using namespace std;

int n, cnt = 1;
int map[NUM][NUM] = { 0, };
int x, y;
int d[4][2] = {
	{0, 0},
	{0, 1},
	{1, 0},
	{1, 1}
};
int reverse[4] = { 3, 2, 1, 0 };

void check(int deep, int _x, int _y);
void fill(int dir, int deep, int _x, int _y);

int main() {
	int t; cin >> t;
	n = 1 << t;

	if ((n * n - 1) % 3 != 0) {
		printf("-1\n");
		return 0;
	}

	cin >> x >> y;
	y = n - y;
	x = x - 1;
	map[y][x] = -1;
	
	check(t, 0, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%2d ", map[i][j]);
		}
		printf("\n");
	}
}

void check(int deep, int _x, int _y) {
	if (!deep) return;

	int n = 1 << (deep - 1), dir = 3, tX = n, tY = n;

	if (y < (_y + n)) {
		dir -= 1;
		tY = 0;
	}

	if (x < (_x + n)) {
		dir -= 2;
		tX = 0;
	}

	fill(dir, deep, _x, _y);
	check(deep - 1, _x + tX, _y + tY);
}

void fill(int dir, int deep, int _x, int _y) {
	if (deep == 1) {
		for (int i = 0; i < 4; i++) {
			if (dir == i) continue;
			map[_y + d[i][1]][_x + d[i][0]] = cnt;
		}
		cnt++;
		return;
	}

	int n = 1 << (deep - 1);

	for (int i = 0; i < 4; i++) {
		if (dir == i) continue;
		fill(::reverse[i], deep - 1, _x + (n * d[i][0]), _y + (n * d[i][1]));
	}
	fill(dir, deep - 1, _x + (n / 2), _y + (n / 2));
}