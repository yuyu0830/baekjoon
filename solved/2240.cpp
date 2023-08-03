// DP 골드 5 자두나무 https://www.acmicpc.net/problem/2240
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#define MAX 999999999

using namespace std;

int dp[1002][32] = { 0, };
int drop[501][2] = { 0, };

int max(int a, int b) { return a > b ? a : b; }

void f(int c, int w) {
    for (int i = 1; i <= c; i++) {
        dp[i][0] = dp[i - 1][0] + drop[i][0];
        for (int j = 1; j <= w; j++) {
            int current = drop[i][j % 2 != 0];
            dp[i][j] = max(
                dp[i - 1][j] + current,
                dp[i - 1][j - 1] + current
            );
        }
    }

    printf("%d\n", dp[c][w]);
}

int main() {
    fastio;
    int n, w, c = -1;

    cin >> n >> w;
    int last = 0;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        if (last != t) {
            last = t;
            c++;
        }
        drop[c][t - 1] += 1;
    }
    dp[0][0] = drop[0][0];
    dp[0][1] = drop[0][1];
    f(c + 1, w);
}

