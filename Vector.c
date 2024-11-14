#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Vector.h"

void binaryToHex(char *binary[], int n) {
    for (int i = 0; i < n; i++) {
        int value = 0;
        
        for (int j = 0; j < 8; j++) {
            if (binary[i][j] == '1') {
                value |= (1 << (7 - j)); 
            }
        }

        
        printf("Binary: %s -> Hex: %#X\n", binary[i], value);
    }
}
