// 구현 실버 4 solved.ac https://www.acmicpc.net/problem/18110
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int arr[300001];

int main() {
    int n; cin >> n;

    if (!n) {
        printf("0\n");
        return 0;
    }

    int cut = (int) round((float) n * 0.15);
    int sum = 0;
    
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        sum += t;
        arr[i] = t;
    }

    sort(arr, arr + n);
    
    for (int i = 0; i < cut; i++) {
        sum -= arr[i];
        sum -= arr[n - i - 1];
    }

    printf("%d\n", (int) round((float) sum / (n - cut - cut)));
}