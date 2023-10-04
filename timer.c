/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

bool alarm_off = false;
time_t start, stop;

void handler1(int signum)
{ //signal handler for SIGUSR1
  printf("Hello World!\n");
  alarm_off = true;
}

void handler2(int signum)
{ //signal handler 2 for SIGUSR2
  printf("Turing was Right!\n");
  alarm_off = true;
}

void handler3(int signum)
{ //signal handler for SIGINT
  time_t stop;
  printf("Hello World!\n");
  alarm_off = true;
}

int main(int argc, char * argv[])
{
  start = time(NULL);
  signal(SIGUSR1,handler1); //register handler to handle SIGALRM
  signal(SIGUSR2,handler2);
  signal(SIGINT,handler3);
  alarm(1); //Schedule a SIGALRM for 1 second
  while(alarm_off == false){ //busy wait for signal to be delivered
    printf("Turing was right!\n")
    sleep(1)
  }
  stop = time(NULL);
  printf("Time of execution: %d, stop - start")
  return 0; //never reached
}