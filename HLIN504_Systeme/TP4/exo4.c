#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char** argv[]){
  printf("parent : %d\n",getppid());
  return 0;
}
