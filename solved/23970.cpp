// 정렬 골드 4 알고리즘 수업 - 버블 정렬 3 https://www.acmicpc.net/problem/23970
#include <iostream>

#define fastio cin.tie(NULL); cin.sync_with_stdio(false);

using namespace std;

int arr[2][10001] = {0, };
int n, arrPtr = 0;

bool same() {
    for (int i = arrPtr; i < n; i++) {
        if (arr[0][i] != arr[1][i]) return false;
        arrPtr++;
    }
    return true;
}

int main() {
    fastio 

    cin >> n;
    for (int i = 0; i < 2; i++) 
        for (int j = 0; j < n; j++) 
            cin >> arr[i][j];
        
    int cnt = n - 1, ptr = 0;

    if (same()) {
        printf("1\n");
        return 0;
    }

    while (cnt) {
        int a = arr[0][ptr];
        int b = arr[0][ptr + 1];

        arr[0][ptr] = min(a, b);
        arr[0][ptr + 1] = max(a, b);

        if (++ptr == cnt) {
            ptr = 0;
            cnt--;
        }
        if (same()) {
            printf("1\n");
            return 0;
        }
    }
    printf("0\n");
}