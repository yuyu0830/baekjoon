#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

#define MAX 999999999

using namespace std;

int dp[10001] = { 0, };

int main() {
    dp[0] = 1;
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        for (int b = a; b <= k; b++) {
            dp[b] += dp[b - a];
        }
    }
    printf("%d\n", dp[k]);
}