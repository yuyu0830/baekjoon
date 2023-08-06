// 해결은 했는데 왜틀렸을까?
//DP 골드 1 할 일 정하기 1 https://www.acmicpc.net/problem/1311
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

#define MAX 999999999

using namespace std;

int n;
int c[20][20] = { 0, }; // 입력값
int dp[1 << 20] = { 0, }; // dp 배열
int m;

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }
    m = (1 << n) - 1;
}

int f(int worker, int work) {
    if (worker == m) return 0;
    // 모든 일이 배정된 경우

    if (dp[worker]) return dp[worker];

    int d = MAX;

    for (int i = 0; i < n; i++) {
        int workerBit = 1 << i;
        if (worker & workerBit) continue; // 이미 일하고 있는 사람이면 패스

        int nWorker = worker | workerBit; // i번째 사람 비트마스킹

        for (int j = 0; j < n; j++) {
            if (work & (1 << j)) continue; // 이미 누가 맡은 일이면 패스

            int nWork = work | (1 << j); // j번째 일 비트마스킹
            d = min(f(nWorker, nWork) + c[i][j], d); // 최소값 갱신
        }
    }
    dp[worker] = d;
    return d;
}

int main() {
    input();
    int ans = f(0, 0);
    printf("%d\n", ans);
}