// BFS 골드 5 숨바꼭질 3 https://www.acmicpc.net/problem/13549
//BFS 골드 5 숨바꼭질 3 https://www.acmicpc.net/problem/13549
#include <iostream>
#include <vector>
#include <queue>

#define M(x, y) make_pair(x, y)
#define MAX 99999999

using namespace std;

typedef pair<int, int> ii;

int n, k;
bool visited[100001] = {0, };

int solve() {
    priority_queue<int, vector<int>, greater<int>> q[2];
    bool e = false;

    q[e].push(n);
    visited[n] = 1;

    int cnt = 0;

    if (n == k) return 0;

    while (true) {
        while (!q[e].empty()) {
            int cur = q[e].top();

            q[e].pop();

            for (ii i : {M(cur - 1, 1), M(cur * 2, 0), M(cur + 1, 1)}) {
                if (i.first < 0 || i.first > 100000) continue;

                if (i.first == k) return cnt + i.second;

                if (!visited[i.first]) {
                    visited[i.first] = 1;
                    q[e ^ i.second].push(i.first);
                }

                if (cur > k) break;
            }

            if (cur > k) {
                q[e] = priority_queue <int, vector<int>, greater<int>> ();
                break;
            }
        }
        
        e = !e;
        cnt++;
    }

    return 0;
}

int main() {
    cin >> n >> k;
    printf("%d\n", solve());
}