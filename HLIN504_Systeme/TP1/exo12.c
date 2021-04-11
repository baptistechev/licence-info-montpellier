#include <stdio.h>

int f1(){
  int tab[10];
  for(int i=0;i<10;i++)
    tab[i] = i;
  for(int i=0;i<10;i++)
    printf("%p\n",&tab[i]);
}
int f2(){
  int tab2[10];
  printf("\n");
  for(int i=0;i<10;i++)
    printf("%p\n",&tab2[i]);
}
int main(void){
  f1();
  f2();
  return 0;
}
