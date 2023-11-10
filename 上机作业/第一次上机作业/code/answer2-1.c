#include <stdio.h>
#include <math.h>

#define N 11 // 插值节点的数量

double f(double x) {
    return 1.0 / (1 + x * x);
}

int main() {
    double x[N];
    double A[N];  // 存储差商的数组
    double y[N];
    double TMP[N];
    int i, j;

    // 初始化节点
    for (i = 0; i < N; i++) {
        x[i] = -5 + i;
        printf("x[%d]=%f\n",i,x[i]);
    }

    //计算插值节点值f(x_i)
    for(int i = 0;i < N; i++){
        y[i] = f(x[i]);
        printf("Y[%d]=%f\n",i,y[i]);
    }

    //计算差商
    A[0] = y[0];
    for (int m = 1; m < N; m++) { // 外层m阶差商
        double result_sum = 0;
        for (int i = 0; i <= m; i++) { // 计算求和
            double result_prod = 1;
            double result_frac = 0;
            for (int j = 0; j <= m; j++) { // 计算分母的连乘积
                if (j != i) {
                    result_prod *= x[i] - x[j];
                }
            }
            result_frac = y[i] / result_prod;
            result_sum += result_frac;
        }
        A[m] = result_sum;
        printf("A[%d] = %f\n", m, A[m]);
    }


    // 输出多项式形式的结果
    printf("N(x)=");
    for(int k = 0;k < N; k++){
        printf("(%f)",A[k]);
        for(int n = 0;n < k; n++){
            if(k > 0) printf("*");
            printf("(x-%f)",x[n]);
        }
        if(k<N-1) printf("+");
    }
    printf("\n");

    return 0;
}
