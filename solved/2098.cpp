//DP 골드 1 외판원 순회 https://www.acmicpc.net/problem/2098
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

#define MAX 999999999

using namespace std;

int n;
int c[16][16] = { 0, }; // 입력값
int dp[1 << 16][16] = { 0, }; // dp 배열

void input();
int f(int v, int n);

int main() {
	input();

	int ans = f(0, 0);
	if (ans == MAX) ans = -1;

	printf("%d", ans);
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c[i][j];
		}
	}
}

// v : 이미 방문한 도시 비트 조합
// n : 이번에 지날 도시 번호
int f(int v, int now) {
	// n 비트마스킹 해서 v에 기록
	v |= (1 << now);

	// 만약 모든 지역을 지났다면
	if (v == (1 << n) - 1) {
		// 마지막에 n 에서 시작위치(0)으로 돌아오기가 가능하면
		if (c[now][0] > 0) {
			// 여행비용 반환
			return c[now][0];
		}
		// 불가능하면 MAX 반환
		return MAX;
	}

	// r에 현재 위치, 지나간 지역 dp 배열 값 저장
	int& r = dp[v][now];
	
	// r이 0이 아니라면 r은 이미 계산된 것이므로 r 반환
	if (r > 0) return r;

	// r이 0이라면 처음이니까 연산해주자
	// 현재 갈 수 있는 지역 전부 계산
	r = MAX;
	for (int i = 0; i < n; i++) {
		// 아직 안가본 곳일 경우
		// 1 << i 가 현 지역 비트니까 v랑 비트 and 연산 조지기
		// c[n][i] 가 0 보다 큼(길이 있음)
		if (((v & (1 << i)) == 0) && (c[now][i] > 0)) {

			// t 변수에 새로 갈 지역 + 지금까지 지난 지역으로 재귀함수 호출
			// 현재 지역에서 새로운 지역 가는 값 더하기
			int t = f(v, i) + c[now][i];

			// 만약 t가 더 작다면 r에 t 대입
			if (t < r) r = t;
		}
	}

	return r;
}