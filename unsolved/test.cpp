#include <iostream>

int main() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d%d ", i, j);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d%d ", 2 - j, i);
        }
        printf("\n");
    }
}