#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int nbc = 0;
float frequences[256];
struct noeud{
  int pere;
  int fg;
  int fd;
  float freq;
};
struct noeud arbre[511];
char* codes[256];

/* Lire fichier
Tableau 256 float
compte le nb de chaque char
*/

void calculFrequences(char* fichier){
  for(int i=0;i<256;i++) frequences[i]=0;
  FILE* fd=fopen(fichier,"r");
  int c;
  while((c = fgetc(fd))!=EOF){
    // printf("%c\n",c);
    frequences[c]++;
    nbc++;
  }
  
  printf("Calcul des frequences ...\n\n");
  for(int i=0;i<256;i++){
    frequences[i]/=nbc;
    if(frequences[i]>0)printf("%c ( %i ) : %f\n",i,i,frequences[i]);
  }
}

void creerArbre(){
  
  for(int i = 0;i<511;i++){
    arbre[i].pere = -1;
    arbre[i].fg = -1;
    arbre[i].fd = -1;
    arbre[i].freq = 0;    
    if(i<256) arbre[i].freq = frequences[i];
  }

  int idMin1,idMin2,idPere = 255;
  float freqMin1,freqMin2;

  do{

    idMin1=-1;idMin2=-1;
    freqMin1=1,freqMin2=1;

    for(int i=0;i<510;i++){
      if(arbre[i].pere == -1 && arbre[i].freq != 0){
	if(arbre[i].freq < freqMin1){
	  idMin1 = i;
	  freqMin1 = arbre[i].freq;
	}
      }
    }
    
    for(int i=0;i<510;i++){
      if(arbre[i].pere == -1  && arbre[i].freq != 0){
	if(arbre[i].freq < freqMin2 && i!=idMin1){
	  idMin2 = i;
	  freqMin2 = arbre[i].freq;
	}
      }
    }

    if(idMin1 != -1 && idMin2 != -1){
      idPere++;
      arbre[idPere].fd = idMin1;
      arbre[idPere].fg = idMin2;
      arbre[idPere].freq = freqMin1 + freqMin2;
      arbre[idMin1].pere = idPere;
      arbre[idMin2].pere = idPere;
    }
  
  }while(idMin1 != -1 && idMin2 != -1);
  printf("\nGeneration de l'arbre ...\n\n");
  for(int i = 0;i<511;i++){
    if(arbre[i].freq !=0){
      printf("%i : pere=%i fg=%i fd=%i freq=%f \n",i,arbre[i].pere,arbre[i].fg,arbre[i].fd,arbre[i].freq);
    }
  }
  
}

void parcours(int noeud, char* code){
  if(arbre[noeud].fg !=-1 && arbre[noeud].fd !=-1){
    char* codeG = (char*) malloc(strlen(code)+1);
    char* codeD = (char*) malloc(strlen(code)+1);
    strcpy(codeG,code);
    strcpy(codeD,code);
    codeG[strlen(code)]='0';
    codeD[strlen(code)]='1';  
    parcours(arbre[noeud].fg,codeG);
    parcours(arbre[noeud].fd,codeD);
  }else{
    codes[noeud]=strdup(code);
  }
}

void codeHuffman(){
  int dernierNoeud;
  for(int i=256;arbre[i].pere!=-1;i++){
    dernierNoeud=i+1;
  }
  parcours(dernierNoeud,"");
  printf("\nGeneration des codes binaires...\n");
  for(int i=0;i<256;i++){
    if(frequences[i]!=0){
      printf("%c : %s \n",i,codes[i]);
    }
  }
}

void createFile(char* fichier){
  FILE* fd=fopen(fichier,"r");

  char* nomFC = (char*) malloc(strlen(fichier)+3);
  strcpy(nomFC,fichier);
  strcat(nomFC,".cp");
  FILE* fc=fopen(nomFC,"w");

  //creation Index
  if(nbc==0){
    printf("\n-----------Terminer !------------\n\n");
    return;
  }
  fprintf(fc,"%d\n",nbc);
  int nbcInd = 0;
  for(int i=0;i<256;i++){
    if(codes[i]!=0){
      if(strlen(codes[i])<10){
	nbcInd += 4 + strlen(codes[i]);
      }else if(strlen(codes[i])<100){
	nbcInd += 5 + strlen(codes[i]);
      }else{
	nbcInd += 6 + strlen(codes[i]);
      }
    }
  }
  fprintf(fc,"%d\n",nbcInd);
  for(int i=0;i<256;i++){
    if(codes[i]!=0){
      fprintf(fc,"%c",i);
      fprintf(fc,"%li",strlen(codes[i]));
      fprintf(fc," ");
      fprintf(fc,"%s\n",codes[i]);
    }
  }
  
  //Generation du flux
  
  char* buff = malloc(262*sizeof(char));  
  int c;
  while((c = fgetc(fd))!=EOF){
    if(buff[7]!=0){
      //fputc des 8 premiers caracteres
      int somme=0;
      char* nb = (char*) malloc(1*sizeof(char));
      for(int i=7;i>=0;i--){
	nb[0] = buff[i];
	somme += atoi(nb) * pow(2,7-i);
      }
      //printf("%i\n",somme);
      fputc(somme,fc);

      //decaler
      for(int i=0;i<255;i++){
	buff[i]=buff[i+8];
      }
      strcat(buff,codes[c]); 
    }else{
      strcat(buff,codes[c]);     
    }
  }
  if(buff[0]!=0){
    //completer dernier octet
    strcat(buff,"0000000");
    int somme=0;
    char* nb = (char*) malloc(1*sizeof(char));
    for(int i=7;i>=0;i--){
      nb[0] = buff[i];
      somme += atoi(nb) * pow(2,7-i);
    }
    //printf("%i\n",somme);
    fputc(somme,fc);
  }

  printf("\n-----------Terminer !------------\n\n");
  
}

int main(int argc,char** argv){

  calculFrequences(argv[1]);
  
  //creation Arbre
  if(nbc!=0){
    creerArbre();
  
  //Generation du code Huffman
  codeHuffman();
  }
  
  //creation du fichier compressé
  createFile(argv[1]);
  
  return 0;
}
