// 플로이드-워셜 골드 4 플로이드 https://www.acmicpc.net/problem/11404
#include <iostream>

#define MAX 99999999

using namespace std;

int arr[102][102] = {0, };

int main() {
    int n, m; cin >> n >> m;

    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) 
            arr[i][j] = MAX;

    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        arr[a][b] = c < arr[a][b] ? c : arr[a][b];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[j][i] == MAX) continue;

            for (int k = 1; k <= n; k++) {
                if (j == k) continue;
                int t = arr[j][i] + arr[i][k];
                arr[j][k] = t < arr[j][k] ? t : arr[j][k];
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] == MAX) printf("0 ");
            else printf("%d ", arr[i][j]);

        }
        printf("\n");
    }

}