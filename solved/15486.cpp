// DP 골드 5 퇴사 2 https://www.acmicpc.net/problem/15486
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX 999999999

using namespace std;

int arr[1500002] = { 0, };

int main() {
    fastio;
	int n, d, t;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> d >> t;
		if (i + d <= n) arr[i + d] = max(arr[i + d], arr[i] + t);
		if (i) arr[i] = max(arr[i], arr[i - 1]);
	}
	printf("%d\n",arr[n - 1]);
}

