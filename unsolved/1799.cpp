#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

int leftArr[20] = {0, };
int rightArr[20] = {0, };
int map[11][11] = {0, };

int n, ans = 0, m = 0;
vector<ii> v;

void solve(int idx) {
    int x = v[idx].first;
    int y = v[idx].second;

    int rightPos = x + y;
    int leftPos = (n - x - 1) + y;

    if (map[x][y] && !rightArr[rightPos] && !leftArr[leftPos]) {
        rightArr[rightPos] = 1;
        leftArr[leftPos] = 1;

        m = max(m, ++ans);

        for (int i = idx + 1; i < v.size(); i++) {
            solve(i);

            if (ans + (v.size() - i - 1) <= m) return;
        }

        rightArr[rightPos] = 0;
        leftArr[leftPos] = 0;

        ans--;
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int t; cin >> t;
            map[i][j] = t;
            if (t) v.push_back(make_pair(i, j));
        }
    }

    for (int i = 0; i < v.size(); i++) {
        solve(i);

        if (ans + v.size() - i - 1 < m) break;
    }

    printf("%d\n", m);
}