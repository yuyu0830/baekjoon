// DP 골드 4 색종이 올려놓기 https://www.acmicpc.net/problem/2643
#include <iostream>
#include <vector>
#include <math.h>
#include <cstring>
#include <algorithm>

#define MAX 999999999
#define NUM 102
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

typedef struct ii {
	int x, y;
	ii() { 
		x = 0, y = 0;
	};
	ii(int X, int Y) : x(X), y(Y) {};
};

int n;
int arr[NUM] = { 0, };
int ans = 0;
ii v[NUM];

bool comp(const ii a, const ii b) {
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

bool isin(ii a, ii b) {
	if (b.x >= a.x && b.y >= a.y) return true;
	return false;
}

void input() {
	cin >> n;
	int a, b;
	for (int i{}; i < n; i++) {
		cin >> a >> b;
		v[i] = { min(a, b), max(a, b) };
	}
	sort(v, v + n, comp);
}

void f() {
	for (int i{}; i < n; i++) {
		int m = 1;
		for (int j{}; j < i; j++){
			if (isin(v[j], v[i])) {
				m = max(arr[j] + 1, m);
			}
		}
		arr[i] = m;
		ans = max(m, ans);
	}
}


int main() {
	input();
	f();
	printf("%d\n", ans);
}

