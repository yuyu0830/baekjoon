// 유니온 파인드 골드 5 집합의 표현 https://www.acmicpc.net/problem/1717
#include <iostream>

#define fastio cin.tie(NULL); cin.sync_with_stdio(false);

using namespace std;

int parent[1000001] = {0, };

int find(int v) {
    if (parent[v] == v) return v;
    return parent[v] = find(parent[v]);
}

void merge(int x, int y) {
    parent[find(x)] = find(y);
}

bool isUnion(int x, int y) {
    return find(x) == find(y);
}

int main() {
    fastio
    int n, m; cin >> n >> m;

    for (int i = 1; i <= n; i++) 
        parent[i] = i;
    
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;

        if (a) printf("%s\n", isUnion(b, c) ? "YES" : "NO");
        else merge(b, c);
    }
}