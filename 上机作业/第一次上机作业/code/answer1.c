#include <stdio.h>
#include <math.h>

// 定义被积函数 x^(i+j)
double f1(int i, int j, double x) {
    return pow(x, i + j);
}

// 定义被积函数 sin(πx) * x^i
double f2(int i, double x) {
    return sin(M_PI * x) * pow(x, i);
}

double f3(double x){
    return sin(M_PI * x);
}

// 梯形法则计算定积分
double integrate(double a, double b, int n, int i, double (*func)(int, double)) {
    double h = (b - a) / n;
    double sum = 0.0;

    for (int k = 0; k <= n; k++) {
        double x = a + k * h;
        double value = func(i, x);

        if (k == 0 || k == n) {
            sum += value / 2.0;
        } else {
            sum += value;
        }
    }

    return sum * h;
}

void solveLinearSystem(double A[3][3], double B[3], double x[3]) {
    // 高斯消元法
    int i, j, k;
    double factor;

    for (i = 0; i < 3; i++) {
        for (j = i + 1; j < 3; j++) {
            factor = A[j][i] / A[i][i];
            for (k = i; k < 3; k++) {
                A[j][k] -= factor * A[i][k];
            }
            B[j] -= factor * B[i];
        }
    }

    // 回代求解
    for (i = 2; i >= 0; i--) {
        x[i] = B[i] / A[i][i];
        for (j = i - 1; j >= 0; j--) {
            B[j] -= A[j][i] * x[i];
        }
    }
}

int main() {
    int n = 3; // 多项式次数
    int i;

    double temp = 0;
    temp = f3(0.5);
    printf("%f\n",temp);

    // 步骤1：计算矩阵A
    double A[3][3];
    for (i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = integrate(0.0, 1.0, 1000, i + j, f1);
            printf("%f\n",A[i][j]);
        }
    }

    // 步骤2：计算数组B
    double B[3];
    for (i = 0; i < n; i++) {
        B[i] = integrate(0.0, 1.0, 1000, i, f2);
        printf("B数组=%f\n",B[i]);
    }

    // 步骤3：解线性方程组 AC = B
    double C[3];
    solveLinearSystem(A, B, C);

    // 步骤4：打印多项式 P(x)
    printf("P(x) = %.6f + %.6fx + %.6fx^2\n", C[0], C[1], C[2]);

    return 0;
}
