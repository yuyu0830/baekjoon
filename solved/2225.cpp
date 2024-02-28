//DP 골드 5 합분해 https://www.acmicpc.net/problem/2225
#include <iostream>

using namespace std;

int dp[202][202] = {0, };

int main() {
    int n, k; cin >> n >> k;
    for (int i = 0; i <= n; i++) dp[1][i] = 1;

    for (int i = 2; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            int tmp = 0;
            for (int m = 0; m <= j; m++) {
                tmp += dp[i-1][m];
                tmp %= 1000000000;
            }
            dp[i][j] = tmp;
        }
    }
    
    printf("%d\n", dp[k][n]);
}