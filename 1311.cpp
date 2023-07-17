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

	// for (int i = 0; i <= m; i++){
	// 	printf("%d : %d\n", i, dp[i]);
	// }
	printf("%d\n", ans);
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

	for (int i = n - 1; i >= 0; --i){
		printf("%d", v >> i & 1);
	}
	
	printf("  %d\n", now);

	if (v == m) return ;

	int& r = dp[v][now];
	if (r != 0) return r;

	r = MAX;
	for (int i = 0; i < n; i++) {
		if ((i != now) && (v & (1 << i)) == 0) {
			int t = f(v, i) + c[now][i];
			if (t < r) r = t;
		}
	}

	return r;
}