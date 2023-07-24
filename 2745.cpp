#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string.h>

#define MAX 999999999

using namespace std;

int main() {
    char c[64]; int b; cin >> c >> b;
    long long ans = 0;
    long long d = 1;
    for (int i = strlen(c) - 1; i >= 0; i--) {
        int t = c[i];
        if (t >= 65) t -= 55;
        else t -= 48;
        ans += t * d;
        d *= b;
    }
    printf("%d\n", ans);
}