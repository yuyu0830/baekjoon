//수학 브론즈 3 세탁소 사장 동혁 https://www.acmicpc.net/problem/2720
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string.h>

#define MAX 999999999

using namespace std;

int main() {
    int n; cin >> n;
    int c[] = { 25, 10, 5, 1 };
    while (n--) {
        int m; cin >> m;
        for (int i = 0; i < 4; i++) {
            printf("%d ", m / c[i]);
            m = m % c[i];
        }
        printf("\n");
    }
}