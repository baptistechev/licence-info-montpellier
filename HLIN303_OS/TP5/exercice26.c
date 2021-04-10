#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tailleL 1000

int main(int argc,char** argv){
  
  if(argc<2){return 1;}
  int nbLigne = 10;
  if(argc >2){
    nbLigne=atoi(argv[2]);
  }
  nbLigne++;
  
  FILE* fc=fopen(argv[1],"r");
  if(fc==NULL){return 2;}
  char** buffer = (char**)malloc(nbLigne*sizeof(char*));
  
  buffer[0] = (char*)malloc(tailleL*sizeof(char));
  
  while(fgets(buffer[0],tailleL,fc)!=NULL){
    for(int i=nbLigne-1;i>0;i--){
      if(buffer[i-1]!=NULL){
	buffer[i] = strdup(buffer[i-1]);
      }
    }
  }
  for(int i=nbLigne-1;i>0;i--){
    printf("%s",buffer[i]);
  }

  return 0;
}
