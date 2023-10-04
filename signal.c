/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  exit(1); //exit after printing
  //if exit(1) is not present, we continue with the infinite
  //loop after we print "Hello World!\n"
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  //jump to handler() function once a SIGALRM is sounded
  alarm(1); //Schedule a SIGALRM for 1 second
  //after the alarm is set, the program runs in an infinite loop
  //once the alarm sounds, we move to the handler and it is runs
  while(1); //busy wait for signal to be delivered
  //while(1) acts as an infinite loop until a break
  return 0; //never reached
}