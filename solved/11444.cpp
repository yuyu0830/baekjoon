// 수학 골드 2 피보나치 수 6 https://www.acmicpc.net/problem/11444
#include <iostream>

#define MOD 1000000007

using namespace std;

class Matrix {
    public:
    long long int a, b, c, d;

    Matrix(long long int A, long long int B, long long int C, long long int D) : a(A), b(B), c(C), d(D) {};

    Matrix(const Matrix& m) {
        this->a = m.a;
        this->b = m.b;
        this->c = m.c;
        this->d = m.d;
    }

    void Adding() {
        long long int _a = this->a;
        long long int _b = this->b;
        long long int _c = this->c;
        long long int _d = this->d;

        this->a = _b;
        this->b = _d;
        this->c = _d;
        this->d = (_c + _d) % MOD;
    }

    void Doubling() {
        long long int _a = this->a;
        long long int _b = this->b;
        long long int _c = this->c;
        long long int _d = this->d;

        this->a = (_a * _a) % MOD + (_b * _c) % MOD;
        this->b = (_a * _b) % MOD + (_b * _d) % MOD;
        this->c = (_c * _a) % MOD + (_d * _c) % MOD;
        this->d = (_c * _b) % MOD + (_d * _d) % MOD;

        this->a %= MOD;
        this->b %= MOD;
        this->c %= MOD;
        this->d %= MOD;
    }
};

int main() {
    long long int n; cin >> n;

    if (!n) { 
        printf("0\n");
        return 0;
    }

    long long int t = 1;
    Matrix m(0, 1, 1, 1);

    bool e[70];
    int cnt = 0;

    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
            e[cnt] = 1;
        }
        else {
            n -= 1;
            e[cnt] = 0;
        }
        cnt++;
    }

    for (int i = cnt - 1; i >= 0; i--) {
        if (e[i]) m.Doubling();
        else m.Adding();
        //printf("::%d : %d\n", i, e[i]);
    }

    printf("%lld\n", m.b);
}