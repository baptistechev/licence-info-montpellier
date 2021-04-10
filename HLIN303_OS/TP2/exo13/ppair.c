#include <stdio.h>
#include <stdlib.h>


int pair(unsigned int i){
  if (i==0)
    return 1;
  else
    return impair(i-1);
}

int impair(unsigned int i){
  if (i==0)
    return 0;
  else
    return pair(i-1);
}

int main(int argc, char** argv){
  unsigned int n = atoi(argv[1]);
  if(pair(n)){
    printf("%i est pair\n",n);
  }else{
    printf("%i est impair\n",n);
  }
}
