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
	for (int i = 1; i <= n; i++) {
		cin >> d >> t;
		if (i + d - 1<= n) {
			arr[i + d - 1] = max(arr[i + d - 1], arr[i - 1] + t);
		}
		arr[i] = max(arr[i], arr[i - 1]);
	}

	printf("%d\n",arr[n]);
}

