#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Vector.h"

int main() {
    int n;
    printf("Enter the number of binary control codes: ");
    scanf("%d", &n);

    // 动态分配内存存储二进制控制码
    char **binary = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        binary[i] = (char *)malloc(9 * sizeof(char)); // 8位 + 结束符
        printf("Enter 8-bit binary code for LED %d: ", i + 1);
        scanf("%s", binary[i]);
    }

    // 调用转换函数
    binaryToHex(binary, n);

    // 释放内存
    for (int i = 0; i < n; i++) {
        free(binary[i]);
    }
    free(binary);

    return 0;
}
