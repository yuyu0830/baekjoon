// 미해결
// DFS 골드 3 텀 프로젝트 https://www.acmicpc.net/problem/9466
#include <iostream>
#include <vector>
#include <math.h>
#include <cstring>
#include <algorithm>

#define MAX 999999999
#define NUM 100002

using namespace std;

int n;
bool e[NUM] = { 0, };
int arr[NUM] = { 0, };

void f() {
	memset(e, 0, NUM);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (i == arr[i]) e[i] = true;
	}
	
	int ans = 0;
	vector<int> v;

	for (int i = 1; i <= n; i++) {
		if (e[i]) continue;

		int tmp = i;
		int comp = arr[i];
		int cnt = 1;

		while (true) {
			v.push_back(comp);
			if (e[comp]) {
				v.clear();
				ans += cnt;
				break;
			}
			else if (tmp == comp) {

			}
			cnt++;
			comp = arr[comp];
		}

		e[i] = true;
	}
	printf("%d\n", ans);
}

int main() {
	int t; cin >> t;
	while (t--) {
		f();
	}
}