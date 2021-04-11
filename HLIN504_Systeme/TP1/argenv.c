#include <stdio.h>/* printf */
#include <stdlib.h>

int main(int argc, char* argv[], char* env[]){
  printf("Nombre d'arguments : %i \n",argc);
  for(int i =0;i<argc;i++)
    printf("%s \n",argv[i]);
  int i =0;
  while(env[i]!=NULL){
    printf("%s \n",env[i]);
    i++;
  }
  printf("Nombre de variables d'environnement : %i \n",i);
  return 0;
}

// argenv un deux 3 : 4
// argenv * $PATH : 4 -> nombre de fichier repertoire courrant + 1
// argenv /.??* : 7 -> nombre de repertoire cachés a la racine
