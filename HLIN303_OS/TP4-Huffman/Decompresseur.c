#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#define taille 1000

char* codes[256];
int nbChar,nbCharInd;
char* file;
FILE* fd;
int c;

void lireIndex(char* fichier){

  file=fichier;
  fd=fopen(fichier,"r");
  char nbCharStr[taille],nbCharIndStr[taille];
  fgets(nbCharStr,taille,fd);
  fgets(nbCharIndStr,taille,fd);
  nbChar = atoi(nbCharStr);
  nbCharInd = atoi(nbCharIndStr);

  //lecture Index

  for(int i=0;i<256;i++){
    codes[i]="";
  }
  
  int i=0,k;
  int codeASCII,tailleCode;
  c = fgetc(fd);
  char* tailleStr = (char*) malloc(3*sizeof(char));
  char* tailleVide = (char*) malloc(3*sizeof(char));
  while(i<nbCharInd){

    codeASCII=c;
    //printf("Charactere : (%i) %c\n",codeASCII,codeASCII);
    k=0;
    c = fgetc(fd);
    tailleStr[1]=' ';
    tailleStr[2]=' ';
    do{
      i++;
      tailleStr[k] = c;
      tailleCode=atoi(tailleStr);
      k++;
    }while((c = fgetc(fd))!=' ');
    i++;
    //printf("taille chaine : %i\n",tailleCode);
    codes[codeASCII]="";
    for(int j=0;j<tailleCode;j++){
      c = fgetc(fd);i++;
      char* code= (char*) malloc(strlen(codes[codeASCII])+1);
      strcpy(code,codes[codeASCII]);
      code[strlen(codes[codeASCII])]=c;
      codes[codeASCII]=strdup(code);
      //printf("chaine %c apres ajout du %i chiffre : %s\n",codeASCII,j,codes[codeASCII]);
    }
    c = fgetc(fd);i++;
    c = fgetc(fd);i++;
  }
  printf("Lecture de l'index ...\n");
  for(int i=0;i<256;i++){
    if(codes[i]!=""){
      printf("(%i) %c %s\n",i,i,codes[i]);
    }
  }
}

int lectureFlux(){

  //creation du fichier dcp
  char* nomFC = (char*) malloc(strlen(file)+4);
  strcpy(nomFC,file);
  strcat(nomFC,".dcp");
  FILE* fc=fopen(nomFC,"w");

  //copie du flux
  char* flux = (char*) malloc(nbChar*256*sizeof(char));
  int puis;
  do{
    for(int n=7;n>=0;n--){
      puis = pow(2,n);
      if(c/puis){// ==1
	c = c%puis;
	strcat(flux,"1");
      }else{
	strcat(flux,"0");
      }
    }
  }while((c = fgetc(fd))!=EOF);
  printf("\nFlux : %s\n",flux);

  int nbCharEcrit=0,i=0;
  char* buff = (char*) malloc(256*sizeof(char));
  char* vide = (char*) malloc(256*sizeof(char));
  char* bChar = (char*) malloc(1*sizeof(char));
  while(nbCharEcrit<nbChar && i<strlen(flux)){ //tant qu'on a pas ecrit le nb de caractere
                             //ecrit dans l'index
    
    bChar[0]=flux[i];
    strcat(buff,bChar);
    //    printf("%s\n",buff);
    for(int j=0;j<256;j++){
      if(strcmp(buff,codes[j]) == 0){
	fputc(j,fc);
	nbCharEcrit++;
	strcpy(buff,vide);
	break;
      }
    }
    i++;
  }
  printf("\n-----------Terminer !------------\n\n");
}

int main(int argc,char** argv){

  lireIndex(argv[1]);

  lectureFlux();
  
  return 0;
}

