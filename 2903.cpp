#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string.h>

#define MAX 999999999

using namespace std;

int main() {
    int n, v = 2; cin >> n;
    while (n--) {
        v += v - 1;
    }
    printf("%d", v * v);
}