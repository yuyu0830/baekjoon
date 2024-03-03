// 재귀 실버 1 팰린드롬 파티션 https://www.acmicpc.net/problem/2705
#include <iostream>

using namespace std;

int n;
int cnt;
int arr[1001] = {0, };

int f(int v) {
    if (arr[v]) {
        cnt += arr[v];
        return arr[v];
    }

    int c = 0;

    if (v % 2 == 0) {
        for (int i = 2; i <= v; i += 2) {
            c += f((v - i) / 2);
        }

        c += f(v / 2);
    }

    else {
        for (int i = 1; i <= v; i+= 2) {
            c += f((v - i) / 2);
        }
    }
    
    arr[v] = c;

    return c;
}

int main() {
    int testCase; cin >> testCase;

    arr[0] = 1; arr[1] = 1;

    while (testCase--) {
        cin >> n;
        cnt = 0;

        arr[n] = f(n);

        if (n > 4 && n % 2 == 0) cnt += arr[2];

        printf("%d\n", arr[n]);
    }
}