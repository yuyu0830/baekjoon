// 구현 실버 5 집합 https://www.acmicpc.net/problem/11723
#include <iostream>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

using namespace std;

int main() {
    fastio;
    int n; cin >> n;
    int ans = 0;

    while (n--) {
        char str[7]; cin >> str;
        int t;

        if (str[0] == 'a') {
            if (str[1] == 'd') { //add
                cin >> t;
                ans |= (1 << (t - 1));
            }

            else  //all
                ans |= ~(0);
    
            continue;
        }

        if (str[0] == 'r') { //remove
            cin >> t;
            ans &= ~(1 << (t - 1));
            continue;
        }

        if (str[0] == 'c') { //check
            cin >> t;
            if (ans & (1 << (t - 1))) printf("1\n");
            else printf("0\n");
            continue;
        }

        if (str[0] == 't') { //toggle
            cin >> t;
            ans ^= 1 << (t - 1);
            continue;
        }

        if (str[0] == 'e') { //empty
            ans = 0;
            continue;
        }
    }
}