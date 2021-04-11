#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[], char *env[]){
  
  pid_t racine = getpid();

  char *str = (char *) malloc(100*sizeof(char));
  do{
    scanf("%s", str);
    //parcourir le path et si str est dans le path
    //recouvrir le processus fils avec le chemin du path menant à str
    /*
    char *ptr = strtok(argv[1], ":");
  
    while (ptr != NULL){

      char *s = strcat(ptr, str);
      
      printf("'%s'\n", s);
      ptr = strtok(NULL, ":");
    }
    */
    
    fork();
    if(getpid() != racine)
      execl(str, str, (char *) NULL);
  }while(strcmp(str, "exit()"));
  
  return 0;
}
