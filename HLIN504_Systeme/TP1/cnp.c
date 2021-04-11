#include <stdio.h>/* printf */
#include <stdlib.h>

int trianglePascal(int p, int n){
  int* triangle[n];
  for(int i =0;i<=n;i++)
    triangle[i] = malloc(i*sizeof(int)+1);
  triangle[0][0] = 1;
  for(int i =1;i<=n;i++){
    for(int j=0;j<i+1;j++){
      if(j <= 0){
	triangle[i][j] = triangle[i-1][j];	
      }else if(j >= i){
	triangle[i][j] = triangle[i-1][j-1];
      }else{
	triangle[i][j] = triangle[i-1][j] + triangle[i-1][j-1];
      }
    }
  }
  for(int i =0;i<=n;i++){
    for(int j=0;j<i+1;j++){
      printf("%i ",triangle[i][j]);
    }
    printf("\n");
  }

  return triangle[n][p];
}

int main(int argc, char* argv[]){
  if(argc != 3)
    return 1;
  printf("Le nombre de combinaison de %s parmi %s est : %i \n", argv[1],argv[2],trianglePascal(atoi(argv[1]),atoi(argv[2])));
  return 0;
}
