#include <stdio.h>
#include <math.h>

#define N 11 // 节点数量

double f(double x) {
    return 1.0 / (1.0 + x * x);
}

int main() {
    double x[N]; // 等距节点
    double y[N]; // 存储函数值

    for(int i = 0; i < N; i++) {
        x[i] = - 5 + i ;
    }

    for (int i = 0; i < N; i++) {
        y[i] = f(x[i]);
        printf("x[%d] = %.4f  y[%d] = %.4f\n",i,x[i],i,y[i]);
    }

    // 计算三次样条插值
    double h[N - 1];
    for (int i = 0; i < N - 1; i++) {
        h[i] = x[i + 1] - x[i];
    }

    double alpha[N - 1];
    for (int i = 1; i < N - 1; i++) {
        alpha[i] = (3.0 / h[i]) * (y[i + 1] - y[i]) - (3.0 / h[i - 1]) * (y[i] - y[i - 1]);
    }

    double l[N], mu[N], z[N];
    l[0] = 1.0;
    mu[0] = 0.0;
    z[0] = 0.0;

    for (int i = 1; i < N - 1; i++) {
        l[i] = 2.0 * (x[i + 1] - x[i - 1]) - h[i - 1] * mu[i - 1];
        mu[i] = h[i] / l[i];
        z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i];
    }

    double c[N], b[N], d[N];
    l[N - 1] = 1.0;
    z[N - 1] = 0.0;
    c[N - 1] = 0.0;

    for (int j = N - 2; j >= 0; j--) {
        c[j] = z[j] - mu[j] * c[j + 1];
        b[j] = (y[j + 1] - y[j]) / h[j] - h[j] * (c[j + 1] + 2.0 * c[j]) / 3.0;
        d[j] = (c[j + 1] - c[j]) / (3.0 * h[j]);
    }

    // 输出样条曲线表达式
    printf("样条曲线表达式：\n");
    for (int i = 0; i < N - 1; i++) {
        printf("区间 %d: %.2f <= x <= %.2f\n", i, x[i], x[i + 1]);
        printf("S(x) = %.4f + (%.4f)*(x - %.2f) + (%.4f)*(x - %.2f)^2 + (%.4f)*(x - %.2f)^3\n", y[i], b[i], x[i], c[i], x[i], d[i], x[i]);
    }

    return 0;
}
