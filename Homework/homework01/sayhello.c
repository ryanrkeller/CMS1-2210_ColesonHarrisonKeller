#include <stdio.h>
#include <stdlib.h>

   int main( int argc, char * argv[] ) {
      char name[15];
      
      printf("What is your name? ");
      fgets(name, 15, stdin);
      printf("\n\n   Hello, %s\n\n", name);

   }