/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>

bool alarm_off = false;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  alarm_off = true;
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  alarm(1); //Schedule a SIGALRM for 1 second
  while(alarm_off == false){ //busy wait for signal to be delivered
    printf("Turing was right!\n");
    sleep(1);
  }
  return 0; //never reached
}