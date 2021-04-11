#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
//char *getcwd(char *buf, size_t size);
//char *strstr(const char *meule_de_foin, const char *aiguille);
//char *strtok(char *str, const char *delim);

#define N 300

int main(int argc, char* argv[], char* env[]){
  char* str = malloc(N * sizeof(int));
  getcwd(str,N);
  printf("%s\n",str);
  printf("%s\n",env[42]);  

  char* p = strstr(env[42],str);
  printf("%s\n",(p==NULL)?("La chaine n'est pas presente"):("La chaine est presente"));
  
}
