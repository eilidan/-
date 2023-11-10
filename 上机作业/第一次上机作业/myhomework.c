#include <stdio.h>
#include <math.h>

// 定义被积函数 sin(πx) * x^i
double f(double x, int i) {
    return sin(M_PI * x) * pow(x, i);
}

// 梯形法则计算定积分
double integrate(double a, double b, int n, int i) {
    double h = (b - a) / n;
    double sum = 0.0;

    for (int j = 0; j <= n; j++) {
        double x = a + j * h;
        if (j == 0 || j == n) {
            sum += f(x, i) / 2.0;
        } else {
            sum += f(x, i);
        }
    }

    return sum * h;
}

int main() {
    int i;
    for (i = 0; i <= 2; i++) {
        double a = 0.0; // 积分下限
        double b = 1.0; // 积分上限
        int n = 1000;  // 子区间数，可以根据需要调整

        double result = integrate(a, b, n, i);
        printf("i = %d, Integral result: %lf\n", i, result);
    }

    return 0;
}
