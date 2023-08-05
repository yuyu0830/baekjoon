// 백트래킹 골드 5 암호만들기 https://www.acmicpc.net/problem/1759

#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX 999999999

using namespace std;

int n, m;
int arr[16] = { 0, };
int mo = 0, ja = 0;
bool e[16] = { 0, };
string s;

bool isMo(int v) {
	if (v == 97 || v == 101 || v == 105 || v == 111 || v == 117) return true;
	return false;
}

void f(int idx) {
	//printf("%d, %c\n", idx, arr[idx]);
	if (s.size() == n) {
		if (mo && ja >= 2) printf("%s\n", s.c_str());
	}

	for (int i = idx; i < m; i++) {
		bool mj = isMo(arr[i]);
		if (!e[i]) {
			e[i] = true;
			if (mj) mo++;
			else ja++;
			s += (char)arr[i];
			f(i);
			s.resize(s.size() - 1);
			if (mj) mo--;
			else ja--;
			e[i] = false;
		}
	}
}

int main() {
    fastio;
    cin >> n >> m;
	for (int i = 0; i < m; i++) {
		char t; cin >> t;
		arr[i] = (int)t;
	}
	sort(arr, arr + m);
	f(0);

}

