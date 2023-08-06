// DP 실버 1 스티커 https://www.acmicpc.net/problem/9465
#include <iostream>
#include <cstring>
#include <math.h>
#include <algorithm>

#define MAX 999999999

using namespace std;

int n;
int arr[100002][2] = { 0, };

void input() {
	memset(arr, 0, sizeof(arr));
	cin >> n;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[j][i];
		}
	}
	arr[1][0] += arr[0][1];
	arr[1][1] += arr[0][0];
}

int f() {
	int m = max(arr[1][0], arr[1][1]);
	for (int i = 2; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			arr[i][j] += max(arr[i - 2][!j], arr[i - 1][!j]);
			if (arr[i][j] > m) m = arr[i][j];
		}
	}
	return m;
}

int main() {
	int t; cin >> t;
	while (t--) {
		input();
		printf("%d\n", f());
	}
}