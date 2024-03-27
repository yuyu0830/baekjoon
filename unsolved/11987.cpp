// 스패닝 트리 골드 4 최소 스패닝 트리 https://www.acmicpc.net/problem/1197
#include <iostream>
#include <vector>

using namespace std;

#define MP(x, y) make_pair(x, y)





// int n, e, cnt = 1, value = 0, ans = 99999999;
// bool visited[10001] = {0, };
// vector<pair<int, int>> v[10001];

// void solve(int t) {
//     if (cnt == n) {
//         ans = value < ans ? value : ans;
//         return;
//     }

//     for (auto p : v[t]) {
//         if (!visited[p.first]) {
//             visited[p.first] = 1;
//             cnt++;
//             value += p.second;

//             solve(p.first);

//             visited[p.first] = 0;
//             cnt--;
//             value -= p.second;
//         }
//     }
// }

// int main() {
//     cin >> n >> e;
//     for (int i = 0; i < n; i++) {
//         int a, b, c; cin >> a >> b >> c;
//         v[a].push_back(MP(b, c));
//         v[b].push_back(MP(a, c));
//     }

//     for (int i = 1; i <= n; i++) {
//         visited[i] = 1;
//         solve(i);
//         visited[i] = 0;
//     }

//     printf("%d\n", ans);
// }