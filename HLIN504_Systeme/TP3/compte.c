#include <stdio.h>/* printf */
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(int argc, char* argv[]){
  if(argc != 2)
    return 1;
  int fd;
  fd = open(argv[1],O_RDONLY);
  if(fd <0)
    return 2;

  int cpt[255];
  for(int i =0;i<255;i++)
    cpt[i] = 0;
  int nb=0;
  char c;
  while(1 == read(fd, &c, 1)){
    if(cpt[c]==0){
      cpt[c] = 1;
      nb++;
    }
  }
  
  printf("%i caracteres differents : ",nb);
  for(int i =0;i<255;i++)
    if(cpt[i]!=0)
      printf("%c ", i);
  printf("\n");
  
  return 0;
}
