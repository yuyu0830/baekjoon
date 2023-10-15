// 그리디 플레5 큰 수 만들기 https://www.acmicpc.net/problem/16496
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

vector<string> v;

bool cmp(string a, string b) {
    return a + b > b + a;
}

int main() {
    int n; cin >> n;
    while (n--) {
        string a; cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end(), cmp);

    if (v[0] == "0") cout << 0;
    else {
        for (string c : v) {
            cout << c;
        }
    }
}