// DP 골드 5 무한수열 https://www.acmicpc.net/problem/1351
#include <iostream>
#include <queue>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#define MAX 999999999
#define NUM 1000000
using namespace std;

typedef struct ii {
    int x;
    long long int y;
    ii(int X, long long int Y) : x(X), y(Y) {};
    ii* next = nullptr;
};

long long int n;
int p, q;
ii* dp[NUM + 1] = { nullptr, };

long long int find(int t, int n) {
    if (dp[n] != nullptr) {
        ii* tmp = dp[n];
        while (tmp) {
            if (tmp->x == t) return tmp->y;
            else tmp = tmp->next;
        }
    }
    return 0;
}

void push(long long int p, long long int v) {
    int t = p / NUM;
    int tp = p % NUM;

    ii* a = new ii(t, v);

    if (!dp[tp]) dp[tp] = a;
    else {
        ii* tmp = dp[tp];
        while (tmp->next) tmp = tmp->next;
        tmp->next = a;
    }
}

long long int f(long long int n) {
    int t = n / NUM;
    int tn = n % NUM;

    long long int ret = find(t, tn);
    if (ret) return ret;

    long long int tp = n / p;
    long long int tq = n / q;

    long long int pp = f(tp);
    long long int qq = f(tq);

    push(tp, pp);
    push(tq, qq);

    return pp + qq;
}

int main() {
    fastio;
    push(0, 1);

    cin >> n >> p >> q;

    long long int ans = f(n);
    printf("%lld\n", ans);
}

