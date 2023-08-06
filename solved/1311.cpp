//DP 골드 1 할 일 정하기 1 https://www.acmicpc.net/problem/1311
#include <iostream>
#include <cstring>
#include <math.h>
#include <algorithm>

#define MAX 999999999

using namespace std;

int n, m;
int c[21][21] = { 0, }; // 입력값
int dp[1 << 21] = { 0, }; // dp 배열

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }
    m = (1 << n) - 1;
    memset(dp, -1, sizeof(dp));
}

int f(int v, int work) {
    if (v == n) {
        if (work == m) return 0;
        else return MAX;
    }

    int& r = dp[work];
    if (r != -1) return r;

    r = MAX;

    for (int i = 0; i < n; i++) {
        int bit = 1 << i;
        if (work & bit) continue;
        r = min(f(v + 1, work | bit) + c[v][i], r);
    }

    return r;
}

int main() {
    input();
    printf("%d\n", f(0, 0));
}