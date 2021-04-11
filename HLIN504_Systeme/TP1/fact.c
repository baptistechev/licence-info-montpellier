#include <stdio.h>/* printf */
#include <stdlib.h>

int fact(int n){
  if(n<=1)
    return 1;
  else
    return n*fact(n-1);
}

int main(int argc, char* argv[]){
  if(argc != 2)
    return 1;
  printf("%i\n",fact(atoi(argv[1])));
  return 0;
}
