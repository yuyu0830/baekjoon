// Queue 실버 4 큐 https://www.acmicpc.net/problem/10845
#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n; cin >> n;

    queue<int> q;

    while (n--) {
        char str[10]; cin >> str;

        if (str[0] == 'p') {
            if (str[1] == 'u') { //push
                int t; cin >> t;
                q.push(t);
            }

            else { //pop
                if (q.empty()) 
                    printf("-1\n");
                else {
                    printf("%d\n", q.front());
                    q.pop();
                }
            }

            continue;
        }

        if (str[0] == 'f') { //front
            if (q.empty()) 
                printf("-1\n");
            else 
                printf("%d\n", q.front());

            continue;
        }

        if (str[0] == 's') { //size
            printf("%d\n", q.size());

            continue;
        }

        if (str[0] == 'e') { //empty
            if (q.empty())
                printf("1\n");
            else
                printf("0\n");
            continue;
        }

        if (str[0] == 'b') { //back
            if (q.empty()) 
                printf("-1\n");
            else 
                printf("%d\n", q.back());
            continue;
        }
    }
}