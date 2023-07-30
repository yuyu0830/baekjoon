#include <iostream>
#include <queue>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#define MAX 999999999
#define NUM 1000000
using namespace std;

typedef struct ii {
    int ptr;
    long long int v;
    ii(int X, long long int V) : ptr(X), v(V) {};
    ii* next = nullptr;
};

long long int n;
int p, q;
ii* dp[NUM + 1] = { nullptr, };

long long int find(int front, int back) {
    if (dp[back] != nullptr) {
        ii* tmp = dp[back];
        while (tmp) {
            if (tmp->ptr == front) return tmp->v;
            else tmp = tmp->next;
        }
    }
    return 0;
}

void push(long long int p, long long int v) {
    int front = p / NUM;
    int back = p % NUM;

    ii* a = new ii(front, v);

    if (!dp[back]) dp[back] = a;
    else {
        ii* tmp = dp[back];
        while (tmp->next) tmp = tmp->next;
        tmp->next = a;
    }
}

long long int f(long long int n) {
    int front = n / NUM;
    int back = n % NUM;

    long long int ret = find(front, back);
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

