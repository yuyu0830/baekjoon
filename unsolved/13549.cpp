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
int arr[100001] = {0, };

struct cmp{
    bool operator()(int a, int b) {
        return arr[a] > arr[b];
    }
};

int solve() {
    for (int i = 0; i < 100001; i++) 
        arr[i] = MAX;

    priority_queue<int, vector<int>, cmp> q;
    q.push(n);
    visited[n] = 1;
    arr[n] = 0;

    while (!q.empty()) {
        int cur = q.top();
        if (cur < 3) printf("%6d : %2d, %d\n", cur, arr[cur], q.size());
        q.pop();

        if (cur == k) 
            return arr[cur];

        for (ii i : {M(cur, 0), M(-1, 1), M(1, 1)}) {
            int fir = cur + i.first;
            int sec = arr[cur] + i.second;

            if (fir < 0 || fir > 10000) continue;

            if (!visited[fir]) {
                visited[fir] = 1;
                q.push(fir);
            }

            arr[fir] = min(arr[fir], sec);
        }
    }

    return 0;
}

int main() {
    cin >> n >> k;
    printf("%d\n", solve());
}