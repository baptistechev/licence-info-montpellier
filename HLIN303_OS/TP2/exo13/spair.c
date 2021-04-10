#include <stdio.h>
#include <stdlib.h>
#include "pair.h"
#include "impair.h"

int main(int argc, char** argv){
  unsigned int n = atoi(argv[1]);
  if(pair(n)){
    printf("%i est pair\n",n);
  }else{
    printf("%i est impair\n",n);
  }
}
