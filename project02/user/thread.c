#include "user/thread.h"

int
thread_create(void (*start_routine)(void*, void*), void *arg1, void *arg2)
{
  void *stack;
  if ((stack= malloc(2*PGSIZE)) == 0)
    return -1;

  int tid = clone(start_routine, arg1, arg2, stack);
  if (tid < 0) {
    free(stack);
    return -1;
  }

  return tid;
}

int thread_join()
{
  void *stack;

  int tid = join((void**)&stack);
  if (tid < 0)
    return -1;

  free(stack);

  return tid;
}