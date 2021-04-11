#include <stdio.h>/* printf */
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define N 16

int main(int argc, char* argv[]){
  if(argc != 2)
    return 1;
  int fd;
  fd = open(argv[1],O_RDONLY);
  if(fd <0)
    return 2;

  int tot = 0;
  char* str = (char *) malloc(N * sizeof(char));
  
  while( 0 != read(fd, str, N)){
    tot +=N;
    printf("%x : ", tot);

    for(int i =0;i<N;i++){
      if(i%2 ==0)
	printf("%x",str[i]);
      else
	printf("%x ",str[i]);
    }
    for(int i =0;i<N;i++)
      printf("%c",str[i]);
    printf("\n");
  }
  
  return 0;
}
