#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
    if(argc != 2) {
        puts("Please use 1 text file as a command line argument.");
        exit(1);
    }
    FILE* input = fopen(argv[1], "r");
    if(!input) {
        printf("File '%s' does not exist.\n", argv[1]);
        exit(2);
    }
    int wordcount = 0;
    int was_whitespace = 1;
    int c;
    while ((c = fgetc(input)) != EOF) {
        if(isspace(c) && !was_whitespace) {
            wordcount++;
        }
        was_whitespace = isspace(c);
    }
    if(!was_whitespace) wordcount++;
    printf("\nWord Count: %d\n",wordcount);
    fclose(input);
    exit(0);
}
