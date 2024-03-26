//DFS 실버 2 연결 요소의 개수 https://www.acmicpc.net/problem/11724
#include <iostream>
#include <vector>

using namespace std;

vector<int> v[1001];
bool visited[1001] = {0, };
int n, m;

int main() {
    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int ans = 0;
    vector<int> dfs;

    for (int i = 1; i <= m; i++) {
        if (visited[i]) continue;

        dfs.push_back(i);
        ans++;

        while (!dfs.empty()) {
            int cur = dfs.back();
            dfs.pop_back();

            for (int t : v[cur]) {
                if (!visited[t]) {
                    visited[t] = 1;
                    dfs.push_back(t);
                }
            }
            
        }
    }

    printf("%d\n", ans);
}