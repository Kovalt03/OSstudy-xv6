#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[]){
  fprintf(1, "My student ID is 2021026108\n");
  uint64 pid = getpid();
  uint64 ppid = getppid();
  fprintf(1, "My pid is %ld\n", pid);
  fprintf(1, "My ppid is %ld\n", ppid);
  return 0;
}

