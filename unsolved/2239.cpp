// 백트래킹 골드 4 스도쿠 https://www.acmicpc.net/problem/2239
#include <iostream>

using namespace std;

int sudoku[9][9] = {0, 0};

bool solve(int pos) {
    int x = pos % 9;
    int y = pos / 9;

    if (sudoku[y][x]) {
        solve(pos + 1);
        return;
    }

    int arr[9];

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sudoku[j][x] == i) break;
            if (sudoku[y][j] == i) break;

            
        }
    }
}

int main() {
    for (int i = 0; i < 81; i++)
        cin >> sudoku[i / 9][i % 9];

    solve(0);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d", sudoku[i][j]);
        }
        printf("\n");
    }
}