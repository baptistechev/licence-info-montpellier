#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char** argv[]){
  printf("%d processus p\n",getpid());
  pid_t fils = fork();
  printf("%d processus f\n",fils);
  int b;
  scanf("%i", &b);
  return 0;
}
