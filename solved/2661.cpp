// 백트래킹 골드 4 좋은수열 https://www.acmicpc.net/problem/2661
#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#define MAX 999999999

using namespace std;

int n;

bool f(string s) {
    for (int i = 1; i <= s.size() / 2; i++) {
        string a = s.substr(s.size() - i, i);
        string b = s.substr(s.size() - (i * 2), i);
        if (a == b) return false;
    }
    return true;
}

bool ff(string s) {
    if (s.size() == n) {
        printf("%s\n", s.c_str());
        return true;
    }
    
    for (int i = 1; i <= 3; i++) {
        char t = 48 + i;
        string ts = s + t;
        if (f(ts)) {
            if (ff(ts)) return true;
        }
    }
    return false;
}

int main() {
    fastio;
    cin >> n;
    ff("");
}

