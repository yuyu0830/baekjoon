// 스택 골드 2 후위 표기식 https://www.acmicpc.net/problem/1918
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool f(char c) {
    if (c == '+' || c == '-') return true;
    return false;
}

bool ff(char a, char b) {
    if (f(a) && (b == '*' || b == '/')) return true;
    return false;
}

int main() {
    string str;
    cin >> str;

    stack<char> s, sign;

    string ans = "";
    
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 65 && str[i] <= 90) 
            ans.push_back(str[i]);
        
        else {
            if (sign.empty()) {
                sign.push(str[i]);
            }

            else {
                if (str[i] == '(') {
                    sign.push(str[i]);
                }

                else if (str[i] == ')') {
                    while (!sign.empty() && sign.top() != '(') {
                        ans.push_back(sign.top());
                        sign.pop();
                    }

                    if (!sign.empty()) sign.pop();
                }

                else {
                    if (sign.top() != '(' && f(sign.top()) == f(str[i])) {
                        ans.push_back(sign.top());
                        sign.pop();
                    }

                    else if (ff(str[i], sign.top())) {
                        ans.push_back(sign.top());
                        sign.pop();

                        if (!sign.empty() && f(sign.top())) {
                            ans.push_back(sign.top());
                            sign.pop();
                        }
                    }

                    sign.push(str[i]);
                }
            }
        }
    }

    while (!sign.empty()) {
        ans.push_back(sign.top());
        sign.pop();
    }

    printf("%s\n", ans.c_str());
}