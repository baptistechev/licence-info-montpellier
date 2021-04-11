#include <stdio.h>

int main(void){
  int tab[10];
  for(int i=0;i<10;i++)
    tab[i] = i;
  for(int i=0;i<10;i++)
    printf("%p : %i \n",&tab[i], tab[i]);
  
  int tab2[10];
  printf("\n");
  for(int i=0;i<10;i++)
    printf("%p : %i \n",&tab2[i], tab2[i]);
  
  return 0;
}
