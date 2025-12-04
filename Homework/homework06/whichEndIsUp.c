// resources used: https://www.quora.com/How-can-I-programatically-check-whether-a-machine-is-little-Endian
                // https://www.cs-fundamentals.com/tech-interview/c/c-program-to-check-little-and-big-endian-architecture

#include <stdio.h>

int main() {
    unsigned int x = 0xBEEFCAFE;
    unsigned char *c = (unsigned char*) &x;

    printf("*c is 0x%x\n", *c);

    if (*c == 0xFE) {
        printf("This machine is little endian\n");
    } else {
        printf("This machine is big endian\n");
    }

    return 0;
}
