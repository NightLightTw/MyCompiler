#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

// 創建矩陣
void create_matrix(int a[][MAX_SIZE], int n, int m) {
    srand(time(NULL)); // 設定種子
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = rand() % 100; // 隨機生成 0 到 99 的整數
        }
    }
}

// 顯示矩陣
void print_matrix(int a[][MAX_SIZE], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

// 矩陣相乘
void matrix_multiply(int a[][MAX_SIZE], int b[][MAX_SIZE], int c[][MAX_SIZE], int n, int m, int p) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            c[i][j] = 0;
            for (int k = 0; k < m; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main() {
    int a[MAX_SIZE][MAX_SIZE], b[MAX_SIZE][MAX_SIZE], c[MAX_SIZE][MAX_SIZE];
    int n, m, p;

    printf("請輸入矩陣大小（格式：a*b b*c）：");
    scanf("%d*%d %d*%d", &n, &m, &m, &p);

    // 創建矩陣並顯示
    // create_matrix(a, n, m);
    // create_matrix(b, m, p);
    // printf("矩陣 A：\n");
    // print_matrix(a, n, m);
    // printf("矩陣 B：\n");
    // print_matrix(b, m, p);

    // 矩陣相乘
    matrix_multiply(a, b, c, n, m, p);

    // 顯示矩陣 C
    printf("矩陣 C：\n");
    print_matrix(c, n, p);

    return 0;
}

