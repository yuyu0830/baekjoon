// 투포인터 골드 5 두 용액 https://www.acmicpc.net/problem/2470
#include <iostream>
#include <algorithm>
#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#define VALUE(x) (x.first * x.second)

using namespace std;

typedef pair<int, int> ii;

ii arr[100001];

int main() {
    fastio
    int n; cin >> n;

    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        arr[i] = make_pair(abs(t), t < 0 ? -1 : 1);
    }

    sort(arr, arr + n);

    int ans = 2147000000;
    int a, b, t;

    for (int i = 1; i < n; i++) {
        int x = VALUE(arr[i - 1]);
        int y = VALUE(arr[i]);
        t = abs(x - (y * -1));

        if (t < ans) {
            ans = t;
            a = min(x, y);
            b = max(x, y);
        }
    }

    printf("%d %d\n", a, b);
}