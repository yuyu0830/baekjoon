// 그리디 골드 2 보석도둑 https://www.acmicpc.net/problem/1202
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

#define fastio cin.tie(NULL); cin.sync_with_stdio(false);

ii gems[300001];
int bags[300001] = {0, };

priority_queue<int> q;

int main() {
    fastio
    int n, k; cin >> n >> k;

    for (int i = 0; i < n; i++) 
        cin >> gems[i].first >> gems[i].second;
    
    for (int i = 0; i < k; i++) 
        cin >> bags[i];
    
    sort(gems, gems + n);
    sort(bags, bags + k);

    long long int ans = 0;
    int cnt = 0;

    for (int i = 0; i < k; i++) {
        int curBag = bags[i];

        while (cnt < n && gems[cnt].first <= curBag) {
            q.push(gems[cnt].second);
            cnt++;
        }

        if (!q.empty()) {
            ans += q.top();
            q.pop();
        }
    }

    printf("%lld\n", ans);
}