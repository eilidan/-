#include <stdio.h>

void calculateDifferences(int m, double x[], double y[], double A[]) {
    for (int i = 0; i <= m; i++) {
        A[i] = y[i];
    }

    for (int k = 1; k <= m; k++) {
        for (int i = m; i >= k; i--) {
            A[i] = (A[i] - A[i - 1]) / (x[i] - x[i - k]);
        }
    }
}

int main() {
    int m = 10; // 十阶差商
    double x[m + 1]; // x数组，存储已知的x值
    double y[m + 1]; // y数组，存储已知的f(x)值
    double A[m + 1]; // 存储差商的数组

    // 输入已知的x和f(x)值
    for (int i = 0; i <= m; i++) {
        printf("请输入x[%d]: ", i);
        scanf("%lf", &x[i]);
        printf("请输入f(x[%d]): ", i);
        scanf("%lf", &y[i]);
    }

    calculateDifferences(m, x, y, A);

    // 打印差商
    printf("差商数组A[10]:\n");
    for (int i = 0; i <= m; i++) {
        printf("A[%d] = %lf\n", i, A[i]);
    }

    return 0;
}
