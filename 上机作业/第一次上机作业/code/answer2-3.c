#include <stdio.h>

int main() {
    // 等距节点
    double x[] = {-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
    int numPoints = 11;

    // 输出分段插值多项式
    for (int i = 0; i < numPoints - 1; i++) {
        double x1 = x[i];
        double x2 = x[i + 1];
        double y1 = 1.0 / (1.0 + x1 * x1);
        double y2 = 1.0 / (1.0 + x2 * x2);
        double slope = (y2 - y1) / (x2 - x1);
        double intercept = y1 - slope * x1;

        printf("在区间 [%.2f, %.2f] 上的插值多项式：\n", x1, x2);
        printf("f(x) = %.6fx + %.6f\n\n", slope, intercept);
    }

    return 0;
}
