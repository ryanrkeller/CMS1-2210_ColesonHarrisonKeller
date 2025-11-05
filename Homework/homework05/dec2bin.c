#include <stdlib.h>
#include <stdio.h>
int main() {
    printf("Please enter an unsigned integer value: ");
    unsigned num = 0;
    scanf("%u",&num);
    unsigned binary[sizeof(unsigned)*8];
    int i;
    for(i = sizeof(unsigned)*8-1; i > -1;i--) {
        binary[i] = num & 1;
        num >>= 1;
    }
    printf("\n");
    for(i = 0; i < sizeof(unsigned)*8;i++) {
        printf("%u",binary[i]);
    }
    printf("\n");
    exit(0);
}