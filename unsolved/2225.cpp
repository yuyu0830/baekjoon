//미해결
//DP 골드 5 합분해 https://www.acmicpc.net/problem/2225
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

#define MAX 999999999

using namespace std;

int dp[201] = {0, };

int main() {
    dp[0] = 1;
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++){
        for (int b = i; b <= n; b++) {
            dp[b] += dp[b - i];
        }
    }

    printf("%d\n", dp[n]);
}
