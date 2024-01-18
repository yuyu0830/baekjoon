#include <iostream>
#include <vector>
#include <queue>

#define fastio ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define MAX 99999999

using namespace std;

typedef pair<int, int> ii;

int v, e, n;
bool visited[20001] = {0, };
int arr[20001] = {0, };
vector<ii> vt[20001];

void dijkstra(int start) {
    arr[start] = 0;
    priority_queue<ii> pq;

    pq.push(make_pair(0, start));
    while (!pq.empty()) {
        int distance = -pq.top().first;
        int current = pq.top().second;

        pq.pop();

        if (arr[current] < distance) continue;

        for (ii i : vt[current]) {
            int nextDistance = distance + i.first;
            int next = i.second;
            if (nextDistance < arr[next]) {
                arr[next] = nextDistance;
                pq.push(make_pair(-nextDistance, next));
            }
        }

    }
}

int main() {
    fastio;
    cin >> v >> e >> n;

    for (int i = 1; i <= v; i++) 
        arr[i] = MAX;
    
    for (int i = 0; i < e; i++) {
        int a, b, len; cin >> a >> b >> len;

        vt[a].push_back(make_pair(len, b));
    }

    dijkstra(n);

    for (int i = 1; i <= v; i++) {
        if (arr[i] == MAX) cout << "INF\n";
        else cout << arr[i] << "\n";
    }
}