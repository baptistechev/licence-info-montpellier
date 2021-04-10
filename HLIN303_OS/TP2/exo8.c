#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv, char** env){
  float moyenne = 0;
  for(int i = 1;i<argc;i++){
    moyenne += atoi(argv[i]);
  }
  printf("La moyenne vaut %f\n",moyenne/(argc-1));
}
