#include <stdio.h>
#include <math.h>


#define N_center 1e7
#define N_trapezoid 1e7
#define N_simpson 1e7

typedef double (*FunctionType)(double);//处理用于传参的函数调用

// 定义被积函数 4*runge
double f_4runge(double i) {
    return 4 / (1 + i * i);
}

// 构造复合中点求积公式函数
double remix_center_point(double a, double b, int n, FunctionType func1) {
    double h;
    double x_frac;
    double f_value;
    double result_sum = 0;
    h = (b - a) / n;
    for (int i = 0; i < n; i++) {
        x_frac = a + ((i + 0.5) * h); 
        f_value = func1(x_frac);
        result_sum += f_value;
    }
    return h * result_sum;
}

//构造复合梯形求积公式函数
double remix_trapezoid(double a, double b, int n, FunctionType func1) {
    double h;
    double x_i;
    double x_i_plus;
    double f_value;
    double f_value_plus;
    double result_sum = 0;
    h = (b - a) / n;
    for (int i = 0; i < n; i++) {
        x_i = a + (i * h); 
        x_i_plus = a + ((i+1) * h); 
        f_value = func1(x_i);
        f_value_plus = func1(x_i_plus);
        result_sum += (f_value + f_value_plus);
    }
    return (h / 2.0000) * result_sum;
}

//构造Simpson求积公式函数
double remix_simposon(double a, double b, int n, FunctionType func1) {
    double h;
    double x_i;
    double x_i_frac;
    double x_i_plus;
    double f_value;
    double f_value_frac;
    double f_value_plus;
    double result_sum = 0;
    h = (b - a) / n;
    for (int i = 0; i < n; i++) {
        x_i = a + (i * h); 
        x_i_frac = a + ((i + 0.5) * h);
        x_i_plus = a + ((i + 1) * h); 
        f_value = func1(x_i);
        f_value_frac = func1(x_i_frac);
        f_value_plus = func1(x_i_plus);
        result_sum += (f_value + 4 * f_value_frac + f_value_plus);
    }
    return (h / 6.0000) * result_sum;
}

//创建用于绘制误差函数的txt坐标数据文件以便用tikz宏包绘制图像
void handleCoordinates(const char *filename, int numPoints, int begin_point, int end_point,double (*func)(double, double, int, double(*)(double))) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("无法创建文件 %s\n", filename);
        return;
    }
    fprintf(file, "h y\n"); // 列名
    int flag = 0;  //用于输出达到定义精度的标志符
    for (double i = 1; i < numPoints; i++) {
        double x = log(i); 
        double y = fabs(M_PI - func(0, 1, i, f_4runge));
        fprintf(file, "%.15lf %.15lf\n", x, y);
        //判断计算结果是否达到所需精度
        if (y < 0.5e-4 && flag == 0)
        {
            printf("达到所需精度的h为：%f，转换后坐标为：%f\n",i+1,log(i+1));
            flag = 1;
        }
    }
    fclose(file);
}



void main(void) {
    double a = 0;
    double b = 0;
    double c = 0;
    const char *filename1 = "中点公式误差坐标.txt";
    const char *filename2 = "梯形公式误差坐标.txt";
    const char *filename3 = "Simpson公式误差坐标.txt";
    a = remix_center_point(0, 1, N_center, f_4runge);
    b = remix_trapezoid(0, 1, N_trapezoid, f_4runge);
    c = remix_simposon(0, 1, N_simpson, f_4runge);
    printf("复合中点公式求出的积分结果为：%.15f\n", a);
    printf("复合梯形公式求出的积分结果为%.15f\n", b);
    printf("复合Simpson公式求出的积分结果为%.15f\n", c);
    handleCoordinates(filename1,70,0,1,remix_center_point);
    handleCoordinates(filename2,70,0,1,remix_trapezoid);
    handleCoordinates(filename3,70,0,1,remix_simposon);
}
