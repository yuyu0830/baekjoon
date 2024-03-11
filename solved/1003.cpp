#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#define MAX 999999999

using namespace std;

typedef pair<int, int> ii;

int f, s;
bool e[41] = {0, };
ii arr[41];

ii addPair(ii a, ii b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

ii fibonacci(int n) {
    if (e[n]) return arr[n];

    if (n == 0) {
        return make_pair(1, 0);
    }
    else if (n == 1) {
        return make_pair(0, 1);
    }

    else {
        ii tmp = addPair(fibonacci(n - 1), fibonacci(n - 2));
        e[n] = true;
        arr[n] = tmp;
        return tmp;
    }
}

int main() {
    fastio;
    int n; cin >> n;
    while (n--) {
        f = 0, s = 0;
        int t; cin >> t;

        ii ans = fibonacci(t);
        printf("%d %d\n", ans.first, ans.second);
    }
}

