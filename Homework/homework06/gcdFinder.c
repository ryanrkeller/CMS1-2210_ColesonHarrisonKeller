#include <stdio.h>
#include <assert.h>

extern int findGCD(int a, int b);

int main() {
    printf("GCD calculation!!\n");

    int result1 = findGCD(10, 5);
    printf("GCD(10, 5) = %d\n", result1);
    assert(result1 == 5);

    int result2 = findGCD(10, 0);
    printf("GCD(10, 0) = %d\n", result2);
    assert(result2 == 10);

    int result3 = findGCD(48, 18);
    printf("GCD(48, 18) = %d\n", result3);
    assert(result3 == 6);

    int result4 = findGCD(13, 7);
    printf("GCD(13, 7) = %d\n", result4);
    assert(result4 == 1);

    int result5 = findGCD(270, 192);
    printf("GCD(270, 192) = %d\n", result5);
    assert(result5 == 6);

    printf("Tests passed!\n");

    return 0;
}
