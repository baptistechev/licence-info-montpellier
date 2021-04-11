#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){

  if(argc != 2)
    return 1;

  pid_t racine = getpid();
  int k = atoi(argv[1]);
  
  printf("processus parent\n");
  int n=0;
  while(racine == getpid() && n<k){
    fork();
    n++;
  }
  printf("processus %d parents %d\n", getpid(),getppid());
  int b;
  scanf("%i", &b);
  
  return 0;
}
