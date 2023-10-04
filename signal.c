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
  signal(SIGALRM,handler); //jump to handler() function 
  //once a SIGALRM is sounded
  alarm(1); //Schedule a SIGALRM for 1 second
  //after the alarm is set, the program runs in an infinite loop
  //once the alarm sounds, we move to the handler and it is run
  while(1); //b
  //acts as an infinite loop until a break
  return 0; //never reached
}