#include <stdio.h>
#include <math.h>

int main() {
    int n = 21;
    double xi[21];
    double yi[21];
    double temp_result[21];

    for (int i = 0; i < n; i++) {
        xi[i] = 5 * cos(((2 * i + 1) / 42.0) * M_PI);
        yi[i] = 1 / (1 + xi[i] * xi[i]);
    }
    
    //为了简化计算先把\prod_{j}^{n}(x_i-x_j)计算出来
    for(int i = 0; i < n; i++){
        double result = 1;
        for(int j = 0; j < n; j++){
            if(i!=j){
            result *= xi[i]-xi[j];
            }
        }
        temp_result[i]=result;
        printf("%f,%f\n",temp_result[i],xi[i]);
    }


    // 计算插值多项式并在指定区间上进行插值
    printf("L(x)=");
    for(int i=0;i<n;i++){
        printf("(%f)*(",yi[i]);
        for(int j=0;j<n;j++){
            if(j!=i){
                if(j==0||i==0){
            printf("(x-%f)",xi[j]);
                }
                else{
                    printf("*(x-%f)",xi[j]);
                }
            }
        }
        printf("/");
        printf("(%f)",temp_result[i]);
        if(i==20){
            printf(")");
        }
        else {
            printf(")+");
        }
    }
    printf("\n");
    return 0;
}