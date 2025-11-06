// sources: borrowed inspiration from https://stackoverflow.com/questions/2150291/how-do-i-measure-a-time-interval-in-c?

#include <sys/time.h>
#include <stdio.h>

int main(void){
     struct timeval t1, t2;
     double elapsedTime;
     int minutes;
     double seconds;


     printf("Welcome to the breath holding test! When ready, take a deep breath and press enter to start the timer, and then press enter again to stop it!");
     getchar();

     gettimeofday(&t1, NULL);

     printf("Timer started! Press enter again to stop the timer once you are finished!");
     getchar();

     gettimeofday(&t2, NULL);

     elapsedTime = (t2.tv_sec - t1.tv_sec) + (t2.tv_usec - t1.tv_usec) / 1000000.0;

     minutes = (int) elapsedTime / 60;
     seconds = elapsedTime - (minutes * 60);

     printf("\nYou held your breath for %d:%05.2f!\n", minutes, seconds);

     return 0;
}