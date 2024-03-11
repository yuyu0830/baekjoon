// 구현 실버 2 마인크래프트 https://www.acmicpc.net/problem/18111
#include <iostream>

#define MAX 99999999

using namespace std;

int cnt[257] = {0, };

int main() {
    int n, m, b; cin >> n >> m >> b;

    int max = 0, min = 256;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int t; cin >> t;

            for (int k = 0; k <= t; k++) 
                cnt[k]++;
            
            max = t > max ? t : max;
            min = t < min ? t : min;
        }
    }

    int ans = MAX;
    int c = 0;

    for (int i = min; i <= max; i++) {
        int ta = 0, tb = 0;
        for (int j = min; j <= max; j++) {
            if (j <= i) {
                ta += (n * m) - cnt[j];
                tb += (n * m) - cnt[j];
            }
            else {
                ta += cnt[j] * 2;
                tb -= cnt[j];
            }
        }

        if (tb <= b) {
            if (ta <= ans) {
                ans = ta;
                c = i;
            }
        }
    }

    printf("%d %d\n", ans, c);

    return 0;
}