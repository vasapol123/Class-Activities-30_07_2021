#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 10

char *to_hex(long value) {
    const char *HEX_DIGITS = "0123456789abcdef";
    char *s = (char*)malloc(sizeof(char) * BLOCK_SIZE);

    if (value < 0) {
        value = value + (1L << 32); // 32-bit value
    }
    while (1) {
        char d[] = {HEX_DIGITS[value & 0xf],'\0'};
        char *temp_str = strdup(s);
        strcpy(s, d);
        strcat(s, temp_str);
        free(temp_str);
        value = value >> 4;
        if (value == 0) {
            break;
        }
    }
    char *temp_str = strdup(s);
    strcpy(s, "0x");
    strcat(s, temp_str);
    free(temp_str);
    return s;
}

int main() {
    char *returned_str = to_hex(-1);
    printf("%s",returned_str);
    free(returned_str);
    return 0;

}