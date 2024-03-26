// 트리 실버 2 트리의 부모 찾기 https://www.acmicpc.net/problem/11725
#include <iostream>
#include <vector>

#define SIZE 100001

using namespace std;

bool visited[SIZE] = {0, };
vector<int> v[SIZE];
int parents[SIZE] = {0, };

int main() {
    int n; cin >> n;

    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    vector<int> tree;
    tree.push_back(1);
    visited[1] = 1;

    while (!tree.empty()) {
        int parent = tree.back();
        tree.pop_back();

        while (!v[parent].empty()) {
            int child = v[parent].back();
            v[parent].pop_back();

            if (visited[child]) continue;

            visited[child] = 1;

            parents[child] = parent;
            tree.push_back(child);
        }
    }

    for (int i = 2; i <= n; i++) {
        printf("%d\n", parents[i]);
    }
}