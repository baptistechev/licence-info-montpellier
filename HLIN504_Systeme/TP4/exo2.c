#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char** argv[]){

  for(int i=0;i<4;i++){
    pid_t nPid;
    if((nPid = fork())==0){
      printf(" un nouveau descendant %d de parent %d\n", getpid(), getppid());
    }else{
      int status;
      wait(&status);
    }
  }
  
  return 0;
}
