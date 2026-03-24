#include "kernel/types.h"
#include "user/user.h"

#define CHILD_CNT 10

void child_work(int id) {
  printf("Child %d started (pid: %d)\n", id, getpid());
  if(id==5) yield();
  for (int i = 0; i < 2147483647; i++) {
    asm volatile("");
  }
  for (int i = 0; i < 2147483647; i++) {
    asm volatile("");
  }
  printf("Child %d finished (pid: %d)\n", id, getpid());
  exit(0);
}

int main() {
  int pid;
  printf("==== Start Test ====\n");

  for (int i = 0; i < CHILD_CNT; i++) {
    pid = fork();
    if (pid == 0) {
      child_work(i);
    } else if (pid < 0) {
      printf("fork Fail\n");
      exit(1);
    }
    sleep(1);
  }

  for (int i = 0; i < CHILD_CNT; i++) {
    wait(0);
  }

  printf("==== E n d Test ====\n");
  exit(0);
}



