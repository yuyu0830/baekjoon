// 구현 브론즈 2 Hashing https://www.acmicpc.net/problem/15829
#include <iostream>

using namespace std;

int main() {
    int n; cin >> n;

    char str[51]; cin >> str;

    long long int ans = 0, mod = 1234567891, r = 31, tmp = 1;

    for (int i = 0; i < n; i++) {
        ans += ((str[i] - 96) * tmp) % mod;
        tmp *= r;
        tmp %= mod;
    }

    printf("%d\n", ans % mod);
}