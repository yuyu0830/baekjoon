#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

vector<string> v;

bool cmp(string a, string b) {
    int cnt = 0;
    while (true) {
        if (a[cnt] > b[cnt]) return true;
        if (a[cnt] < b[cnt]) return false;

        cnt++;
        if (a[cnt] == '\0' || b[cnt] == '\0') {
            if (a[cnt] == '\0' && b[cnt] == '\0') return true;
            bool e = a[cnt] == '\0';
            string* ptr = e ? &b : &a;

            char s = e ? a[cnt-1] : b[cnt-1];
            char l = (*ptr)[cnt];

            while (l != s) {
                cnt++;
                l = (*ptr)[cnt];
                if (l == '\0') break;
            }

            if (l > s) return false;
            return true;
        }
    }
}

int main() {
    int n; cin >> n;
    while (n--){
        string a; cin >> a;
        v.push_back(a);
    }
    
    sort(v.begin(), v.end(), cmp);

    for (string c : v) {
        cout << c;
    }
}