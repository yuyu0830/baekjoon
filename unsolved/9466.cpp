// DFS 골드 3 텀 프로젝트 https://www.acmicpc.net/problem/9466
#include <iostream>
#include <cstring>

#define MAX 999999999
#define NUM 100002
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int n;
int ans = 0;
bool e[NUM] = { 0, };
bool chk[NUM] = { 0, };
int arr[NUM] = { 0, };

int r(int a) {
	if (e[arr[a]]) {
		e[a] = true;
		ans++;
		return 0;
	}

	if (chk[arr[a]]) {
		e[a] = true;
		return arr[a];
	}
	
	chk[a] = true;

	int ret = r(arr[a]);
	if (!ret) ans++;
	else if (ret == a) ret = 0;

	e[a] = true;
	return ret;
}

void f() {
	ans = 0;
	cin >> n;
	memset(e, false, n + 1);
	memset(chk, 0, n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (i == arr[i]) e[i] = true;
	}

	for (int i = 1; i <= n; i++) 
		if (!e[i]) r(i);
    
	printf("%d\n", ans);
}

int main() {
	fastio;
	int t; cin >> t;
	while (t--) {
		f();
	}
}