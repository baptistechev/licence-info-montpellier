#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char** argv[]){
  printf("%d parent %d\n",getpid(),getppid());
  //execl("p2","p2");
  execl("p1","p1");
  return 0;
}
