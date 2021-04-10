#include <stdio.h>
#include <stdlib.h>

char** strsplit(char* chaine, char separ){

  char** chaines = NULL;

  int nbMot = 0;
  for(int i=0;chaine[i]!=0;i++){
    if(chaine[i]==separ){
      nbMot++;
    }
  }
  nbMot++;
  printf("Il y a %i mots\n",nbMot);

  chaines = (char**)malloc((nbMot+1)*sizeof(char*));

  
  int nbLettre=0;
  int n = 0;
  for(int i = 0; chaine[i]!=0;i++){
    if(chaine[i]==separ){
      chaines[n] = malloc(nbLettre*sizeof(char));
      n++;
      nbLettre=0;
    }else{
      nbLettre++;
    }
  }
  chaines[n] = malloc(nbLettre*sizeof(char));
  
  n=0;
  int  j=0;
  for(int i = 0; chaine[i]!=0;i++){
    if(chaine[i]!=separ){
      chaines[n][i-j] = chaine[i];
    }else{
      n++;
      j=i+1;
    }
  }
  chaines[n+1]= 0;
  
  return chaines;
}

int main(int argc, char** argv, char** env){
  char* chaine = "test:mot:bonjour";
  char** mots = strsplit(argv[1],argv[2][0]); //mots = strsplit(chaine,':');
  for(int i =0; mots[i]!=NULL; i++){
    printf("%s\n",mots[i]);
  }
  return 0;
}

