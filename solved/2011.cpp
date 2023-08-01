// DP 골드 5 암호코드 https://www.acmicpc.net/problem/2011
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#define MAX 999999999

using namespace std;

int dp[5002] = { 0, };

int main() {
    fastio;
    string s; cin >> s;
    s = "0" + s;

    dp[0] = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == 48) {
            if (s[i - 1] == 49 || s[i - 1] == 50) {
                dp[i] = dp[i - 2] % 1000000;
            }
            else if (s[i - 1] > 50 || s[i - 1] == 48) {
                printf("0\n");
                return 0;
            }
        }
        else {
            if (s[i - 1] == 49 || (s[i - 1] == 50 && s[i] <= 54)) {
                dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000;
            }
            else dp[i] = dp[i - 1] % 1000000;
        }
    }

    printf("%d\n", dp[s.size() - 1]);
}

