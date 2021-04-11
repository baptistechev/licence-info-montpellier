#include <stdio.h>/* printf */
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
  if(argc != 3)
    return 1;
  int src, dest;
  src = open(argv[1],O_RDONLY);
  if(src <0)
    return 2;
  
  dest= open(argv[2],O_WRONLY);
  if(dest <0){
    dest =  open(argv[2],O_CREAT);
    dest =  open(argv[2],O_WRONLY);
  }

  int c;
  while(1 == read(src,&c,1)){
    write(dest, &c,1);
  }
  
  
  return 0;
}
