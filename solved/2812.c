// 테스트 케이스 통과했습니다
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARRAY_NUM 500010

typedef struct _Stack {
    int arr[MAX_ARRAY_NUM];
    int point;
} Stack;

Stack* s;

Stack* createStack();

__inline void push(Stack* s, int num);
__inline int pop(Stack* s);
__inline int top(Stack* s);
__inline int empty(Stack* s);

int main() {
    s = createStack();

    char str[MAX_ARRAY_NUM];
    int cnt = 0, n, len;

    scanf("%d %d", &len, &n);
    scanf("%s", str);
    
    while (cnt < len) {
        int a = str[cnt] - 48;

        while (n > 0 && empty(s) == 0 && a > top(s)) {
            pop(s);
            n--;
        }

        push(s, a);
        cnt++;        
    }

    while (cnt > len - n) {
        cnt--;
        pop(s);
    }

    for (int i = 0; i < s->point; i++) {
        printf("%d", s->arr[i]);
    }
}

Stack* createStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));

    for (int i = 0; i < MAX_ARRAY_NUM; i++) 
        s->arr[i] = 0;
    
    s->point = 0;

    return s;
}

void push(Stack* s, int num) {
    s->arr[s->point++] = num;
}

int pop(Stack* s) {
    return s->arr[--s->point];
}

int top(Stack* s) {
    if (s->point <= 0) return -1;
    return s->arr[s->point - 1];
}

int empty(Stack* s) {
    return s->point == 0;
}