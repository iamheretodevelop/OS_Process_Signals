#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

void ChildProcess(int child_number) {
  int i;
  pid_t pid, ppid;
  int iterations = random() % 31;  // Random number of iterations, up to 30

  for (i = 0; i < iterations; i++) {
    pid = getpid();
    ppid = getppid();
    printf("Child %d Pid: %d is going to sleep!\n", child_number, pid);
    sleep(random() % 11);  // Sleep for a random duration, up to 10 seconds
    printf("Child %d Pid: %d is awake!\nWhere is my Parent: %d?\n", child_number, pid, ppid);
  }
  exit(0);
}

void ParentProcess() {
    int status;
    pid_t cpid = wait(&status);
    printf("Child Pid: %d has completed\n", cpid);
}

int main() {
  srand(time(NULL));
  int status;
  int child_number;

  // Fork the child processes in a loop
  for (child_number = 1; child_number <= 2; child_number++) {
    int fork_value = fork();
    if (fork_value < 0) {
        perror("Fork failed");
        exit(1);
    } else if (fork_value == 0){
        ChildProcess(child_number);
    } else{
        ParentProcess();
    }
  }
  return 0;
}
