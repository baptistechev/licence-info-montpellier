#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char** argv[]){

  FILE* f = fopen("test", "r");

  char *str = (char *) malloc(5*sizeof(char));

  pid_t d1 = fork();
  pid_t d2 = fork();

  printf("%d parent : %d\n",getpid(),getppid());
  
  fread(str, 5, 1, f);
  printf("%s\n",str);
  return 0;
}
