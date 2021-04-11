#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char** argv[]){
  printf("un texte quelconque\n");
  execl("/home/baptiste/Program/Eclipse/eclipse/eclipse", "eclipse");
  //system("ls");
  printf("end\n");
  return 0;
}
