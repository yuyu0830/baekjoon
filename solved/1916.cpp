// 다익스트라 골드 5 최소비용 구하기 https://www.acmicpc.net/problem/1916
#include <iostream>
#include <queue>
#include <vector>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX 2147000000
#define NUM 1002

using namespace std;

typedef pair<int, int> ii; // city, distance

struct cmp {
    bool operator()(ii a, ii b) {
        if (a.second >= b.second) return true;
        return false;
    }
};

bool e[NUM] = { 0,  };
long long int distance[NUM] = { 0,  };
priority_queue<ii, vector<ii>, cmp> q[2][NUM];

long long int min(long long int a, long long int b) {
    if (a < b) return a;
    return b;
}

int main() {
    fastio;

    for (int i = 1; i <= NUM; i++) {
        ::distance[i] = MAX;
    }

    int n, m; cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b, c; 
        cin >> a >> b >> c;
        q[0][a].push(make_pair(b, c));
    }

    int source, dest; 
    cin >> source >> dest; 
    ::distance[source] = 0;
    
    priority_queue<int, vector<int>, greater<int>> l;
    l.push(source);
    int currentCity;
    
    while (!l.empty()) {
        currentCity = l.top();
        l.pop();

        long long int currentDistance = ::distance[currentCity];
        
        int len = q[e[currentCity]][currentCity].size();

        for (int i = 0; i < len; i++) {
            ii target = q[e[currentCity]][currentCity].top();
            q[e[currentCity]][currentCity].pop();

            int targetCity = target.first;
            long long int targetDistance = target.second;

            if (targetDistance + currentDistance < ::distance[targetCity]) {
                ::distance[targetCity] = targetDistance + currentDistance;
                l.push(targetCity);
            }

            q[!e[currentCity]][currentCity].push(target);
        }

        e[currentCity] = !e[currentCity];
    }

    printf("%lld\n", ::distance[dest]);
}