// DP 실버 3 1, 2, 3 더하기 https://www.acmicpc.net/problem/9095
#include <iostream>

using namespace std;

int arr[12] = {0, };

int main() {
    int testCase; cin >> testCase;

    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;

    for (int i = 4; i < 12; i++) 
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3]; 

    while (testCase--) {
        int n; cin >> n;
        printf("%d\n", arr[n]);
    }
}