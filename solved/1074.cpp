// 분할정복 실버 1 Z https://www.acmicpc.net/problem/1074
#include <iostream>

using namespace std;

int main() {
    int n, r, c; cin >> n >> r >> c;

    int ans = 0;
    int t = 1 << (n * 2);

    for (int i = 0; i < n; i++) { 
        int v = t >> (n - i + 1);
        if (r >= v) ans |= t >> 1;
        if (c >= v) ans |= t >> 2;

        r %= v;
        c %= v;
        t = t >> 2;
    }

    printf("%d\n", ans);
}
