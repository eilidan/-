#include<stdio.h>
#include<math.h>

//定义被积函数
double f_4runge(double i) {
    return 4 / (1 + i * i);
}


// 龙贝格求积法的实现
double romberg_integration(double a, double b, int n) {
    double h[n+1][n+1];
    int i, j;

    // 计算初始梯形积分值
    for (i = 0; i <= n; i++) {
        h[i][0] = 0.5 * (b - a) * (f_4runge(a) + f_4runge(b));
        double factor = 1.0;
        for (j = 1; j <= i; j++) {
            factor *= 4.0;
            h[i][0] *= 0.5;
            double sum = 0.0;
            int k;
            for (k = 1; k <= factor; k += 2) {
                sum += f_4runge(a + k * (b - a) / factor);
            }
            h[i][0] += sum * (b - a) / factor;
        }
    }

    // 利用 Richardson 外推逐步提高精度
    for (j = 1; j <= n; j++) {
        for (i = j; i <= n; i++) {
            h[i][j] = h[i][j-1] + (h[i][j-1] - h[i-1][j-1]) / (pow(4, j) - 1);
        }
    }

    return h[n][n];
}

int main() {
    // 定义积分区间和初始分割数
    double a = 0.0;
    double b = 1.0;
    int n = 9;

    // 调用龙贝格求积法
    double result = romberg_integration(a, b, n);

    // 打印结果
    printf("龙贝格求积法的结果：%lf\n", result);

    return 0;
}
