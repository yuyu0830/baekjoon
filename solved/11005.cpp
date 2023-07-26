//수학 브론즈 2 진법변환 2 https://www.acmicpc.net/problem/3197
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string.h>

#define MAX 999999999

using namespace std;

int main() {
    int n, b; cin >> n >> b;
    int m = b, cnt = 1;
    while (true) {
        if ((long long)m * b > n) break;
        m *= b;
        cnt++;
    }

    if (n >= b) {
        while (cnt--) {
            int t = n / m;
            if (t >= 10) printf("%c", t + 55);
            else printf("%c", t + 48);
            n = n % m;
            m /= b;
        }
    }
    
    if (n >= 10) printf("%c", n + 55);
    else printf("%c", n + 48);
}