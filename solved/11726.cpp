// DP 실버 3 2xn 타일링 https://www.acmicpc.net/problem/11726
#include <iostream>

using namespace std;

int dp[1003] = {0, };

int main() {
    int n; cin >> n;
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i < n + 2; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }

    printf("%d\n", dp[n]);
}