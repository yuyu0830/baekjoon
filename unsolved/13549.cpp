//BFS 골드 5 숨바꼭질 3 https://www.acmicpc.net/problem/13549
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ii;

int n, k;

bool min(int a, int b) { return a < b ? a : b; }

struct cmp{
    bool operator()(ii a, ii b) { 
        return min(k - a.first, k - (a.first * 2)) < min(k - b.first, k - (b.first * 2)); 
    }
};

int solve() {
    priority_queue<ii, vector<ii>, cmp> q;

    q.push(make_pair(0, 0));

    while (!q.empty()) {
        ii cur = q.top();
        q.pop();
        
        if (cur.first > k) {
            q.push(make_pair(0, cur.second + (k - cur.first)));
            continue;
        }

        for (ii i : {-1, 1, cur.first * 2}) {
            if (cur.first + i == k)
        }
    }
}

int main() {
    cin >> n >> k;
    solve();
}