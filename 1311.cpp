#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

#define MAX 999999999

using namespace std;

int n;
int c[20][20] = { 0, }; // 입력값
int dp[1 << 20][20] = { 0, }; // dp 배열
int m;

void input();
int f(int v, int n);

int main() {
	input();

	int ans = f(0, 0);

	printf("%d", ans);
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c[i][j];
		}
	}
	m = (1 << n) - 1;
}


int f(int v, int now) {
	v |= (1 << now);

	if (v == m) {
		return 0;
	}

	int& r = dp[v][now];
	if (r > 0) return r;

	r = MAX;
	for (int i = 0; i < n; i++) {
		if ((v & (1 << i)) == 0) {
			int t = f(v, i) + c[now][i];
			if (t < r) r = t;
		}
	}

	return r;
}