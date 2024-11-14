#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Vector.h"

void binaryToHex(char *binary[], int n) {
    for (int i = 0; i < n; i++) {
        int value = 0;
        
        // 转换每个 8 位二进制数为十进制整数
        for (int j = 0; j < 8; j++) {
            if (binary[i][j] == '1') {
                value |= (1 << (7 - j)); // 从高位到低位设置
            }
        }

        // 输出十六进制数
        printf("Binary: %s -> Hex: %#X\n", binary[i], value);
    }
}
