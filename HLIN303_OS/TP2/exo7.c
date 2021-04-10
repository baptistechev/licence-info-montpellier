#include <stdio.h>

int main(int argc, char** argv, char** env){
  float moyenne = 0;
  float nb;
  for(int i =0;i<5;i++){
    printf("Saisir la %i eme valeur : ",i+1);
    scanf("%f", &nb);
    moyenne += nb;
  }
  printf("La moyenne vaut %f\n",moyenne/5);

}
