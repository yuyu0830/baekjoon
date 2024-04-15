// 문자열 골드 4 문자열 폭발 https://www.acmicpc.net/problem/9935
#include <iostream>
#include <cstring>

using namespace std;

char str[1000001];
char ans[1000001];
char boom[37];
char last;

int ptr, len;

void Explosion() {
    if (ptr <= len - 1) return;

    int pos = ptr - len;

    for (int i = 0; i < len; i++) 
        if (ans[pos + i] != boom[i]) return;
    
    ptr = pos;
}

int main() {
    cin.tie(nullptr);
	ios::sync_with_stdio(false);
    
    cin >> str >> boom;

    len = strlen(boom);
    last = boom[len - 1];
    ptr = 0;

    for (char c : str) {
        ans[ptr++] = c;
        if (c == last) Explosion();
    }

    ans[ptr] = '\0';

    if (!strlen(ans)) printf("FRULA\n");
    else printf("%s\n", ans);
}