#include <stdio.h>
#include <math.h>


#define N 11 // 插值节点的数量
// 目标函数
double targetFunction(double x) {
    return 1.0 / (1.0 + x * x);
}

// 导数函数
double derivativeFunction(double x) {
    return -2.0 * x / pow(1.0 + x * x, 2);
}

double x[] = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5}; // 插值节点数组
int main() {
    double y[11]; // 插值节点对应的函数值
    double y_prime[11]; // 插值节点对应的导数值

    // 初始化插值节点
    for (int i = 0; i < N; i++) {
        y[i] = targetFunction(x[i]);
        y_prime[i] = derivativeFunction(x[i]);
    }

    // 输出插值节点数据
    printf("插值节点和函数值：\n");
    for (int i = 0; i < N; i++) {
        printf("x[%d] = %f, y[%d] = %f, y'[%d] = %f\n", i, x[i], i, y[i], i, y_prime[i]);
    }

    // 分段三次埃尔米特插值
    
    printf("\n分段三次埃尔米特插值表达式：\n");
    for (int i = 0; i < N-1; i++) {
       printf("H(x)=");
       printf("(1+2*(x-%f)/(%f-%f))",x[i],x[i+1],x[i]);
       printf("*(((x-%f)/(%f-%f))^2)",x[i+1],x[i],x[i+1]);
       printf("*(%f)",y[i]);
       printf("+");
       printf("(1+2*(x-%f)/(%f-%f))",x[i+1],x[i],x[i+1]);
       printf("*(((x-%f)/(%f-%f))^2)",x[i],x[i+1],x[i]);
       printf("*(%f)",y[i+1]);
       printf("+");
       printf("(x-%f)",x[i]);
       printf("*((x-%f)/(%f-%f))^2",x[i+1],x[i],x[i+1]);
       printf("*(%f)",y_prime[i]);
       printf("+");
       printf("(x-%f)",x[i+1]);
       printf("*((x-%f)/(%f-%f))^2",x[i],x[i+1],x[i]);
       printf("*(%f)",y_prime[i+1]);
       printf(" x在[%f,%f]\n",x[i],x[i+1]);
    }
    return 0;
}
