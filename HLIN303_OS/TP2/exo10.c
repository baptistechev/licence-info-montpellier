#include <string.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h> 

int str2int(char* str){
  int i=0;
  int nb=0;
  for(int k=strlen(str)-1;k>=0;k--){
    nb=0;
    switch(str[k]){
    case '1':
      nb=1;
      break;
    case '2':
      nb=1;
      break;
    case '3':
      nb=3;
      break;
    case '4':
      nb=4;
      break;
    case '5':
      nb=5;
      break;
    case '6':
      nb=6;
      break;
    case '7':
      nb=7;
      break;
    case '8':
      nb=8;
      break;
    case '9':
      nb=9;
      break;
    default:
      nb=0;
      break;
    }
    i += nb*pow(10,(strlen(str)-k-1));
  }
  return i;
}

char* int2str(int i){

  int k=0;
  int a = i;
  do{
    a/=10;
    k++;
  }while(a!=0);

  char* tab=malloc(k*sizeof(char));

  for(int j=k-1;j>=0;j--){
    tab[j]= (i%10)+48;
    i/=10;
  }
  return tab;
}

int main(int argc, char** argv){

  char* str=int2str(3546);
  printf("%s\n",str);
  return 0;
}
