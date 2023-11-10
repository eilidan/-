#include <stdio.h>

int main() {
    FILE *file;
    int numPoints = 10; // 修改为你需要的坐标点数量
    const char *filename = "coordinates.txt";

    file = fopen(filename, "w");
    
    if (file == NULL) {
        printf("无法创建文件 %s\n", filename);
        return 1;
    }

    fprintf(file, "x y\n"); // 列名

    for (int i = 0; i < numPoints; i++) {
        double x = 2.0 * i; // 修改为你想要的x坐标计算方式
        double y = 1.5 * i; // 修改为你想要的y坐标计算方式
        fprintf(file, "%.2lf %.2lf\n", x, y);
    }

    fclose(file);
    printf("已生成文件 %s 包含 %d 个坐标点。\n", filename, numPoints);

    return 0;
}
