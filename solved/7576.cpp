// BFS 골드 5 토마토 https://www.acmicpc.net/problem/7576
#include <iostream>
#include <vector>
#define MAX 99999999

using namespace std;

typedef struct ii{
    int x, y;
    ii (int X, int Y) : x(X), y(Y) {};
};

int dir[4][2] = {
    { 0, 1 },
    { 0, -1 },
    { 1, 0 },
    { -1, 0 }
};

int arr[1001][1001] = { 0,  };
bool e[1001][1001] = { 0,  };

int zero = 0;
int n, m;
bool flag = false;
vector<ii> v[2];

bool isin(int t, int a){
    if (t >= 0 && t < a) return true;
    return false;
}

void input(){
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            int t; cin >> t;
            if (t) {
                arr[i][j] = t;
                if (t == 1) v[flag].push_back({i, j});
            }
            else zero++;
        }
    }
}

int solv(){
    int cnt = 0;
    while (zero){
        int last = zero;
        while (v[flag].size()){
            ii tmp = v[flag].back();
            v[flag].pop_back();
            
            for (int i = 0; i < 4; i++){
                int x = tmp.x + dir[i][0];
                int y = tmp.y + dir[i][1];
                if (isin(x, m) && isin(y, n) && !e[x][y] && !arr[x][y]){
                    e[x][y] = true;
                    arr[x][y] = true;
                    zero--;
                    v[!flag].push_back({x, y});
                }
            }
        }
        flag = !flag;
        if (zero == last) return -1;
        cnt++;
    }
    return cnt;
}

int main() {
    input();
    int ans = solv();
    printf("%d\n", ans);
}
