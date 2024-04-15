// MST 플래티넘 5 행성터널 https://www.acmicpc.net/problem/2887
#include <iostream>
#include <algorithm>
#include <queue>

#define NUM 100001

using namespace std;

typedef pair<int, int> ii;

struct node {
    int start, end;
    int len;
    node(int s, int e, int l) : start(s), end(e), len(l) {};
};

struct cmp {
    bool operator() (const node& a, const node& b) {
        return a.len > b.len;
    }
};

ii planet[3][NUM];
priority_queue<node, vector<node>, cmp> q;
int parent[NUM] = {0, };

int find(int v) {
    if (parent[v] == v) return v;
    return parent[v] = find(parent[v]);
}
void merge(int x, int y) { parent[find(x)] = find(y); }
bool isUnion(int x, int y) { return find(x) == find(y); }

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> planet[j][i].first;
            planet[j][i].second = i;
        }
    }

    sort(planet[0], planet[0] + n);
    sort(planet[1], planet[1] + n);
    sort(planet[2], planet[2] + n);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            ii a = planet[j][i - 1];
            ii b = planet[j][i];

            q.push(node(a.second, b.second, abs(a.first - b.first)));
        }
    }

    for (int i = 0; i < n; i++) 
        parent[i] = i;
    
    int cnt = 0, ans = 0;

    while (n - cnt != 1) {
        node tmp = q.top();
        q.pop();

        int v1 = tmp.start;
        int v2 = tmp.end;

        if (isUnion(v1, v2)) continue;

        merge(v1, v2);
        cnt++;
        ans += tmp.len;
    }

    printf("%d\n", ans);
}