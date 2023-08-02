// DFS 골드 5 숫자고르기 https://www.acmicpc.net/problem/2668
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
#define MAX 99999999

using namespace std;

typedef struct ii{
    int x, y;
    ii (int X, int Y) : x(X), y(Y) {};
};

int n;
int arr[101] = { 0,  };
bool e[101] = { 0,  };
bool tmp[101] = { 0,  };

bool isin(int t, int a){
    if (t >= 0 && t < a) return true;
    return false;
}

void input(){
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

int solv(){
    
}

int main() {
    input();
    int ans = solv();
    printf("%d\n", ans);
}
