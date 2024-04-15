// 백트래킹 골드 4 스도쿠 https://www.acmicpc.net/problem/2239
#include <iostream>

using namespace std;

int sudoku[9][9] = {0, 0};

bool solve(int pos) {
    if (pos == 81) return true;

    int x = pos % 9;
    int y = pos / 9;

    if (sudoku[y][x]) {
        if (solve(pos + 1)) return true;
        return false;
    }

    int sx = x / 3;
    int sy = y / 3;

    for (int i = 1; i <= 9; i++) {
        bool flag = true;
        for (int j = 0; j < 9; j++) {
            if (sudoku[j][x] == i || sudoku[y][j] == i || sudoku[(sy * 3)+ (j / 3)][(sx * 3) + (j % 3)] == i) {
                flag = false;
                break;
            }
        }

        if (flag) {
            sudoku[y][x] = i;
            if (solve(pos + 1)) return true;
            sudoku[y][x] = 0;
        }
    }

    return false;
}

int main() {
    for (int i = 0; i < 9; i++) {
        char str[10]; cin >> str;
        for (int j = 0; j < 9; j++) {
            sudoku[i][j] = str[j] - 48;
        }
    }

    solve(0);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d", sudoku[i][j]);
        }
        printf("\n");
    }
}