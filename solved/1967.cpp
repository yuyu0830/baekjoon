// DFS 골드 4 트리의 지름 https://www.acmicpc.net/problem/1967
#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

int ans = 0;
queue<ii> q[10001];

int f(int n) {
    priority_queue<int> pq;
    while (!q[n].empty()) {
        ii t = q[n].front();
        q[n].pop();

        if (q[t.first].empty()) {
            pq.push(t.second);
            continue;
        }

        pq.push(f(t.first) + t.second);
    }

    int a = 0, b = 0;

    if (pq.size()) {
        a = pq.top(); 
        pq.pop();
        if (pq.size()) b = pq.top();
    }

    ans = a + b > ans ? a + b : ans;

    return a;
}

int main() {
    int node; cin >> node;
    while (--node) {
        int a, b, c; cin >> a >> b >> c;
        q[a].push(make_pair(b, c));
    }

    f(1);

    printf("%d\n", ans);
}