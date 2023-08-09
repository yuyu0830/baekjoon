// DP 골드 2 모노디지털 표현 https://www.acmicpc.net/problem/2287

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

#define MAX 999999999
#define NUM 32001

using namespace std;

int n, m;
int dp[NUM] = { 0, };
vector<int> v[9];
bool flag = false;

int c(int a, int b, int type) {
	int ret;
	if (!type) ret = a + b;
	else if (type == 1) ret = a - b;
	else if (type == 2) ret = a * b;
	else ret = a / b;
	
	if (ret > 0) return ret;
	else return 0;
}

void f() {
	cin >> n;

	int t = n;
	for (int i = 1; i <= 8; i++) {
		if (t < NUM) dp[t] = i;
		v[i].push_back(t);
		t += n * pow(10, i);
	}

	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j < i; j++) {
			for (int a : v[j]) for (int b : v[i - j]) {
				for (int type{}; type < 4; type++) {
					int tmp = c(a, b, type);
					if (tmp) {
						if (tmp < NUM && !dp[tmp]) dp[tmp] = i;
						v[i].push_back(tmp);
					}
				}
			}
		}
	}

	cin >> m;

	for (int i{}; i < m; i++) {
		cin >> t;
		if (dp[t]) printf("%d\n", dp[t]);
		else printf("NO\n");
	}
}

int main() {
	f();
}