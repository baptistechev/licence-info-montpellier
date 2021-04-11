#include <stdio.h>/* printf */
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
  if(argc != 3)
    return 1;
  int f;
  f = open(argv[1],O_RDONLY);
  if(f <0)
    return 2;

  long deb = 1;
  long fin = lseek(f, 0, SEEK_END) -1;
  long m;
  char c;
  char mC = argv[2][0];
      
  while(deb <= fin){
    m  = (deb+fin)/2;
    lseek(f, m-1, SEEK_SET);
    read(f, &c, 1);
    // printf("%c ", c); 
    if( c < mC ){
      deb = m+1;
    }else if(c > mC){
      fin = m-1;
    }else{
      deb = m+1;
      fin = m-1;
    }
  }

  lseek(f, m-1, SEEK_SET);
  read(f, &c, 1);
  if(c != mC)
    printf("Le caractere n'a pas ete trouve\n");
  else
    printf("%li \n",m);
  
  return 0;
}
