// 누적합 골드 4 부분합 https://www.acmicpc.net/problem/1806
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

#define MAX 999999999
#define NUM 100002

using namespace std;

int n, m;
int ans = 0;
long long int s[NUM] = { 0, };

void f() {
	int big = n;
	int small = n;
	if (s[big] < m) return;
	
	ans = MAX;
	while (small >= 0) {
		while (s[big] - s[small] < m) {
			small--;
		};
		if (big - small < ans) ans = big - small;
		if (s[--big] < m) break;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] += s[i - 1];
	}

	f();
	printf("%d\n", ans);
}