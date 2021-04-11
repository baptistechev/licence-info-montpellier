#include <stdio.h>/* printf */
#include <stdlib.h>

int main(int argc, char* argv[]){
  if(argc != 2)
    return 1;
  FILE *fd = fopen(argv[1],"r");
  if(fd == NULL)
    return 2;

  int cpt[255];
  for(int i =0;i<255;i++)
    cpt[i] = 0;
  
  int c;
  while(EOF != (c = fgetc(fd))){
    cpt[c]++;
  }
  
  for(int i =0;i<255;i++)
    if(cpt[i]!=0)
      printf("%c (%x) : %i ", i, i,cpt[i]);
  printf("\n");
  
  return 0;
}
